#include "thread_pool.h"

// Initialize thread pool with workers number
// Parameter n refers the number of workers in thread pool
//
// TODO: You should implement function to initialize
// thread pool struct with the number of thread workers, n.
// Also, you should properly initialize lock and condition variables

thread_pool* init_thread_pool(int n) {

    return NULL;
}

// Thread function for workers
//
// TODO: For Part 1, this is actual working function to process
// each request by thread workers.
// In this function, the worker should accept requests by
// clients and handle them.
//
// TODO: For Part 2, the workers should get requests from scheduler,
// not accept directly from clients.
// After the workers get requests from schedulers, they handle
// requests and close them.

void* thread_function(void *_arg) {
    
    return NULL;
}

// Function that is called by main thread
//
// TODO: For Part 1, you should implement this function to start your thread_function
// with worker threads.
// It should create each thread workers as the number you initialized before.
//
// TODO: For Part 2, your function should properly convey your SFF scheduler to
// thread_function.
// void start_thread_work(thread_pool* pool, scheduler* sch)

void start_thread_work(thread_pool* pool) {
    
}
