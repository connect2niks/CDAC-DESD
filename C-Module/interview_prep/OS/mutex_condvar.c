#include <stdio.h>
#include <pthread.h>

#define MAX 20

int number = 1;
pthread_mutex_t lock;
pthread_cond_t cond;

void* printOdd(void* arg)
{
    while (number <= MAX)
    {
        pthread_mutex_lock(&lock);

        while (number % 2 == 0)
            pthread_cond_wait(&cond, &lock);

        if (number <= MAX)
        {
            printf("%d ", number);
            number++;
        }

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* printEven(void* arg)
{
    while (number <= MAX)
    {
        pthread_mutex_lock(&lock);

        while (number % 2 != 0)
            pthread_cond_wait(&cond, &lock);

        if (number <= MAX)
        {
            printf("%d ", number);
            number++;
        }

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}

