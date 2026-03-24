#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void recursiveFunction(int count)
{
    if(count == 0)
        return;

    pthread_mutex_lock(&lock);
    printf("Lock count: %d\n", count);

    recursiveFunction(count - 1);

    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&lock, &attr);

    recursiveFunction(3);

    pthread_mutex_destroy(&lock);
}

