#ifndef _MULTIBENCH_H
#define _MULTIBENCH_H

#include <inttypes.h>

typedef uint64_t TYPE;

TYPE *MEMORY_BLOCK_GLOBAL;
uint64_t WORKING_SET_BYTES_GLOBAL;
uint64_t WRITE_BYTES_GLOBAL;
uint64_t LAST_BYTE_WRITTEN_OFFSET;

int mb_to_bytes( int mb );
int bytes_to_mb( int bytes );

int initialize(uint64_t MEMORY_WSS_ARG, uint64_t write_bytes );
int cleanup( void );
uint64_t read_memory( uint64_t write_bytes, int working_set_bytes, uint64_t last_byte_written_offset, TYPE *memory_block );

#endif /* _MULTIBENCH_H */
