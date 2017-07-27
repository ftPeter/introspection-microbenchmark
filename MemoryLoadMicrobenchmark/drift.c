// drift.c
// Peter F. Klemperer
// June 27, 2014
// Drifting memory read/write microbenchmark.

#include "drift.h"

uint64_t kb_to_bytes( int kb )
{
    // 1024 bytes in 1 KB
    return (uint64_t) kb * 1024LL;
}

uint64_t mb_to_bytes( int mb )
{
    // 1048576 bytes in 1 MB
    return (uint64_t) mb * 1048576LL;
}

int bytes_to_mb( uint64_t bytes )
{
    // 1048576 bytes in 1 MB
    return (int)(bytes / 1048576LL);
}

uint64_t gb_to_bytes( int gb )
{
    // 1073741824 bytes in 1 GB
    return (uint64_t) gb * 1073741824LL;
}

// 8kb usage block to bytes
uint64_t blocks_to_bytes(int blocks)
{
    // 8192 bytes in 1 8kb block
    return (uint64_t) blocks * 8192LL;
}

uint64_t optarg_to_bytes()
{
    uint64_t count;
    char unit;

    sscanf(optarg, "%" PRIu64 "%c", &count, &unit );
    if ( unit == 'b' ) {
        count = count;
    } else if ( unit == 'k' ) {
        count = kb_to_bytes( count );
    } else if ( unit == 'm' ) {
        count = mb_to_bytes( count );
    } else if ( unit == 'g' ) {
        count = gb_to_bytes( count );
    }
    return count;
}

void parse_args(int argc, char** argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "b:w:d:t:r:RWs:")) != -1) {
        switch(opt) {
        case 'b':
            BUFFER_SIZE_BYTES = optarg_to_bytes();
            break;
        case 'w':
            WINDOW_SIZE_BYTES = optarg_to_bytes();
            break;
        case 'd':
            WINDOW_DRIFT_BYTES = optarg_to_bytes();
            break;
        case 't':
            TOTAL_ACCESS_BYTES = optarg_to_bytes();
            break;
        case 'r':
            TEST_REPEAT = atoi(optarg);
            break;
        case 'R':
            TEST_READ_OR_WRITE = BLOCK_MEMORY_READ;
            break;
        case 'W':
            TEST_READ_OR_WRITE = BLOCK_MEMORY_WRITE;
            break;
        case 's':
            TEST_SPEED = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s\n", argv[0]);
            fprintf(stderr, "         [-b BUFFER_SIZE_BYTES]\n");
            fprintf(stderr, "         [-w WINDOW_SIZE_BYTES]\n");
            fprintf(stderr, "         [-d WINDOW_DRIFT_BYTES(b|k|m)]\n");
            fprintf(stderr, "         [-t TOTAL_ACCESS_BYTES]\n");
            fprintf(stderr, "\n");
            fprintf(stderr, "         [-R|W] Read or Write\n");
            fprintf(stderr, "         [-s TEST_SPEED] test speed 100,1,..,8\n");
            fprintf(stderr, "\n");
            fprintf(stderr, "         [-r TEST_REPEAT]\n");
            fprintf(stderr, "\n");
            exit(EXIT_FAILURE);
        }
    }
}

// performs the drifting write benchmark
// and returns the number of bytes written
uint64_t load(void *buf)
{
    // TOTAL BYTES ACCESS BY THIS LOAD SO FAR
    uint64_t bytes_accessed = 0;
   
    // TOTAL BYTES TO BE ACCESSED BY THIS LOAD 
    uint64_t total_access_bytes = TOTAL_ACCESS_BYTES;

    // WHICH LOAD IS BEING RUN
    // TODO update this to reflect the different possible loads
    //uint64_t (*memory_load)( uint64_t, TYPE* ) = write_memory;
    uint64_t (*memory_load)( uint64_t, TYPE* ) = \
            get_block_memory_function( TEST_READ_OR_WRITE, TEST_SPEED );

    uint64_t window_start_byte_offset = 0;

    uint64_t buffer_size_bytes  = BUFFER_SIZE_BYTES;
    uint64_t window_size_bytes  = WINDOW_SIZE_BYTES;
    uint64_t window_drift_bytes = WINDOW_DRIFT_BYTES;

    while( bytes_accessed <= total_access_bytes ) {
        /*
        printf("bytes_accessed %" PRIu64 " < total_access_bytes %" PRIu64 "\n",
            bytes_accessed, total_access_bytes );
        */
        uint64_t access_bytes  = window_size_bytes;

        // TODO this shouldn't have to subtract 8192 all the time
        if( ( window_start_byte_offset + access_bytes ) >= buffer_size_bytes - 8192 ) {
            // WRAP-AROUND ACCESS
            access_bytes = buffer_size_bytes - window_start_byte_offset - 8192;
            bytes_accessed += memory_load( access_bytes, 
                                           (TYPE*) (buf + window_start_byte_offset));

            access_bytes = window_size_bytes - access_bytes;
            bytes_accessed += memory_load( access_bytes, 
                                           (TYPE*) (buf + 0));

        } else {
            // STRAIGHT-LINE ACCESS
            /*
            printf("buf %p offset %" PRIu64 " window_size %" PRIu64 " window_drift %" PRIu64 \
                    " buffer_size %" PRIu64 "\n",
                    buf, window_start_byte_offset, window_size_bytes, window_drift_bytes, 
                    buffer_size_bytes );
            printf("accessing window %p\n", buf + window_start_byte_offset );
            */
            // access the window
            bytes_accessed += memory_load( access_bytes, 
                                           (TYPE*) (buf + window_start_byte_offset));
        }
        // DRIFT WINDOW NOW
        window_start_byte_offset += window_drift_bytes;
        if ( window_start_byte_offset >= buffer_size_bytes ) {
            window_start_byte_offset = window_start_byte_offset - buffer_size_bytes;
        }
    }
    return bytes_accessed;
}

int main(int argc, char** argv) {

    parse_args(argc, argv);

    uint64_t memory_wss_bytes  = BUFFER_SIZE_BYTES;

    void *buf = malloc( memory_wss_bytes );

    // start timer
    int64_t start_time_ns   = get_clock_realtime();

    int repeat;
    uint64_t bytes_written = 0;
    if ( TEST_REPEAT == 0 ) TEST_REPEAT = 100;
    for( repeat = 0; repeat < TEST_REPEAT; repeat++) {
        bytes_written += load(buf);
    }
    // end timer
    int64_t end_time_ns     = get_clock_realtime();
    int64_t elapsed_time_ns = end_time_ns - start_time_ns;

    printf("buf %" PRIu64 " window %" PRIu64 " drift %" PRIu64 " total %" PRIu64 \
           " test %s speed %d repeat %d\n",
           BUFFER_SIZE_BYTES, WINDOW_SIZE_BYTES, WINDOW_DRIFT_BYTES, TOTAL_ACCESS_BYTES,
           ( TEST_READ_OR_WRITE == BLOCK_MEMORY_READ ? "read" : "write" ), 
           TEST_SPEED, TEST_REPEAT );
    printf("elapsed time: %f, MB accessed: %" PRIu64 ", BW: %0.3f MB/s \n", 
            (float) elapsed_time_ns / 1.0e9, bytes_written, 
            ( (float) bytes_written * 1.0e9 ) / (1048576.0 * (float) elapsed_time_ns ) );
    //printf("target = %" PRIu64 "\n", target );

    // cleanup
    free( buf );

    return 0;
}
