#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "pool.h"

int main(int argc, char * argv[])
{
    int index,
        common_operate_ret;
    struct tiny_thread_pool new_pool;

    // create manager thread
    pthread_t manager_tid;
    struct manager_thread manager;
    common_operate_ret = pthread_create(&manager_tid, NULL, manager_thread_callback, NULL);
    if (0 != common_operate_ret) {
        return 1;
    }
    manager.manager_tid = manager_tid;

    // create tasker threads
    new_pool.min_thread_num = 5;
    new_pool.max_thread_num = 20;
    for (index = 1; index <= new_pool.min_thread_num; index++) {

    }

    for (index = 0; index < new_pool.alive_thread_num; index++) {

    }

    sleep(199990);
    return 0;
}

void * manager_thread_callback(void * args)
{
    pthread_t tid = pthread_self();
    printf("manager thread %ld created\n", tid);
    /*
     manager thread scan all tasker thread...
     * */
    while (1) {
        printf("ok\n");
        sleep(1);
    }
    return NULL;
}

/*
 * @desc : trigger the tasker thread callback
 * */
void * tasker_thread_callback(void * args)
{
    pthread_t tid = pthread_self();
    printf("tasker thread %ld created\n", tid);
    return NULL;
}