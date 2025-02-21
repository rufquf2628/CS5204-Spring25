#include "scheduler.h"

// Initialize main scheduler
//
// TODO: For Part 2 and 3, you should implement SFF scheduler preventing
// large file starvation
// Parameter n refers the size of buffer

scheduler* init_scheduler(int n) {

    return NULL;
}


// Insert a work for scheduler with fd
// When scheduler buffer is full, waits until worker takes one
// 
// TODO: In this function, you should properly use lock and condition variables
// to achieve producer-consumer relationship of parent thread and worker thread

void insert_scheduler_work(scheduler* sch, thread_pool* pool, int fd) {

}

// Get a work for scheduler with fd
// When scheduler buffer is empty, waits until work is filled
//
// TODO: In this function, you should properly use lock and condition variables
// to achieve producer-consumer relationship of parent thread and worker thread

int get_scheduler_work(scheduler* sch, thread_pool* pool) {
    int conn_fd;
    
    return conn_fd;
}