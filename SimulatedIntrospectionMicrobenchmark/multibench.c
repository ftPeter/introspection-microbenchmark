#include "multibench.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* SHM includes */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

/* globals related to the shm mmio */
int shm_fd;

int mb_to_bytes( int mb )
{
    // 1048576 bytes in 1 MB
    return mb * 1048576;
}

int bytes_to_mb( int bytes )
{
    // 1048576 bytes in 1 MB
    return bytes / 1048576;
}

int initialize(uint64_t MEMORY_WSS_ARG, uint64_t write_bytes )
{
    TYPE *memory_block;
    int memory_wss_bytes  = mb_to_bytes( MEMORY_WSS_ARG ) - 1;
    WORKING_SET_BYTES_GLOBAL = memory_wss_bytes;
    WRITE_BYTES_GLOBAL       = write_bytes;

    /* SNAPSHOT SHM SPECIFIC STUFF */
    /* look to lmbench-3.0-a9-shm/src/bw_mem.c */
    if ((shm_fd = shm_open("/ubuntu-14.04-amd64-qemu2.6", O_RDONLY, (mode_t) 0)) < 0) {
        perror("shm_open");
        exit(1);
    }

    int mmap_flags = (MAP_PRIVATE | MAP_NORESERVE | MAP_POPULATE );
#ifdef MMAP_HUGETLB // since kernel 2.6.32
    mmap_flags |= MMAP_HUGETLB;
#endif // MMAP_HUGETLB

    memory_block = mmap( NULL, memory_wss_bytes, PROT_READ, mmap_flags, shm_fd, (off_t) 0 );
    if( memory_block == MAP_FAILED ) {
        perror("shm mmap");
        exit(1);
    }
    MEMORY_BLOCK_GLOBAL = memory_block;
    /* SHM: shm device allocated */

    printf("# multibench init: %ld WORKING_SET_BYTES_GLOBAL, %ld WRITE_BYTES_GLOBAL\n",
            WORKING_SET_BYTES_GLOBAL, WRITE_BYTES_GLOBAL );

    return 1;
}

int cleanup()
{
    close(shm_fd);
    MEMORY_BLOCK_GLOBAL = 0;
    return 1;
}

static volatile uint64_t  use_result_dummy;
void use_int( int result )
{
    use_result_dummy += result; 
}

// DOIT code lifted from lmbench
#define DOIT(i) p[i]+
uint64_t read_memory( uint64_t write_bytes, int working_set_bytes, uint64_t last_byte_written_offset, TYPE *memory_block )
{
    register TYPE *lastone = memory_block;
    lastone += -1;
    lastone += ( working_set_bytes/sizeof(TYPE) );

    uint64_t bytes_written = 0;

    register int sum = 0;

    register TYPE *p = memory_block;
    p += (last_byte_written_offset/sizeof(TYPE) );
    if( p >= lastone ) p = memory_block;

    while( bytes_written < write_bytes ) {
        // pre write test
        uint64_t bytes_to_write = (uint64_t)(lastone - p + 126) * (uint64_t) sizeof(TYPE);
        if ( (bytes_to_write + bytes_written) > write_bytes ) {
            bytes_to_write = (write_bytes - bytes_written);
            lastone = (p + (bytes_to_write)/sizeof(TYPE) );
        }
        // efficient write loop test
        while( p <= lastone ) {
            sum +=
            DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
            DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
            DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
            DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
            DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
            DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
            DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
            DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
            DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
            DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
            DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
            DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
            DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
            DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
            DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
            DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
            DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
            DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
            DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
            DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
            DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
            DOIT(123) DOIT(124) DOIT(125) DOIT(126) p[127];
            p += 128;
        }
        // post write test
        bytes_written += bytes_to_write;
        p = memory_block;
    }
    last_byte_written_offset = (uint64_t)(lastone + 1024 - memory_block) * \
                                    (uint64_t) sizeof(TYPE);
    last_byte_written_offset &= ~0x3FF;
    LAST_BYTE_WRITTEN_OFFSET = last_byte_written_offset;

    use_int(sum);
    return bytes_written;
}
#undef DOIT


