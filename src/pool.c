#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "pool.h"

int main(int argc, char * argv[])
{
    int index,
        common_operate_ret;
    struct tiny_thread_pool new_pool;
    new_pool.min_thread_num = 5;
    new_pool.max_thread_num = 20;
    for (index = 1; index <= new_pool.min_thread_num; index++) {
        common_operate_ret = pthread_create(&new_pool.tasker_tid_set[index - 1], NULL, tasker_thread_callback, NULL);
        if (0 == common_operate_ret) {
            new_pool.alive_thread_num++;
            new_pool.idle_thread_num++;
        }
    }

    for (index = 0; index < new_pool.alive_thread_num; index++) {
        common_operate_ret = pthread_join(new_pool.tasker_tid_set[index], NULL);
    }

    sleep(199990);
    return 0;
}

void * tasker_thread_callback(void * args)
{
    pthread_t tid = pthread_self();
    printf("thread %ld created\n", tid);
    return NULL;
}