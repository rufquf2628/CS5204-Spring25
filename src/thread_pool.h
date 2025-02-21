#ifndef __THREAD_POOL_H_
#define __THREAD_POOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "request.h"
#include "io_helper.h"

// Thread pool struct
//
// TODO: For Part 1, thread pool struct can have
// data indicates number of worker threads
// and actual worker threads
//
// TODO: For Part 2, the struct should contain
// lock and condition variables for concurrent
// work

typedef struct __thread_pool {

} thread_pool;

thread_pool* init_thread_pool(int n);
void* thread_function(void *_arg);
void start_thread_work(thread_pool* pool);
// void start_thread_work(thread_pool* pool, scheduler* sch);

#endif // __THREAD_POOL_H_