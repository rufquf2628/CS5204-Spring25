#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


// Work struct for threads
//
// TODO: Struct should contain file descriptor of file
// and size of file for sorting

typedef struct _work {
    
} work;

// Main scheduler struct
//
// TODO: Scheduler should have sorted buffer to contain
// works by the order of file size
// Buffer can be other struct or scheduler itself
// Buffer data structure can be anything that can
// efficiently sort and contain works by the order
// of file size

typedef struct _scheduler {
    
} scheduler;

#include "thread_pool.h"

scheduler* init_scheduler(int n);
void insert_scheduler_work(scheduler* sch, thread_pool* pool, int fd);
int get_scheduler_work(scheduler* sch, thread_pool* pool);

#endif //__SCHEDULER_H_