#ifndef TINY_POOL_H
#define TINY_POOL_H 1
#include <pthread.h>

struct manager_thread {
    pthread_t manager_tid;
    int status;
};
struct tasker_thread {
    pthread_t tasker_tid;
    int status;
    struct tasker_thread * next;
};
struct tiny_thread_pool {
    int min_thread_num;
    int max_thread_num;
    int alive_thread_num;
    int idle_thread_num;
    struct manager_thread * manager;
    struct tasker_thread * tasker;
};



void * init_thread_pool();
void * destroy_thread_pool();
void * grace_destroy_thread_pool();
void * add_task_to_pool();
void * scale_pool();
void * tasker_thread_callback(void *);
void * manager_thread_callback(void *);

#endif //TINY_POOL_H end