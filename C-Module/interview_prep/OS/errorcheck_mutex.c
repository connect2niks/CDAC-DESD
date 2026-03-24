#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

int main()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

    pthread_mutex_init(&lock, &attr);

    pthread_mutex_lock(&lock);

    int ret = pthread_mutex_lock(&lock);
    if(ret != 0)
        printf("Error detected: %d\n", ret);

    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
}

