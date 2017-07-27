#ifndef DRIFT_BENCH_H_
#define DRIFT_BENCH_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#include <math.h>

/* getopt includes */
#include <unistd.h>

extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;

typedef uint64_t TYPE;

/* block memory access functions */
#include "block_memory_functions.h"

// PARAMETER GLOBALS
uint64_t BUFFER_SIZE_BYTES;
uint64_t WINDOW_SIZE_BYTES;
uint64_t WINDOW_DRIFT_BYTES;
uint64_t TOTAL_ACCESS_BYTES;
int TEST_SPEED;
int TEST_READ_OR_WRITE;
int TEST_REPEAT;

// Other GLOBALS

// TIMER RELATED FUNCITONS
#include <sys/time.h>
/* real time host monotonic timer */
static inline int64_t get_clock_realtime(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000000LL + (tv.tv_usec * 1000);
}


#endif
