#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 20

int number = 1;
sem_t odd_sem;
sem_t even_sem;

void* printOdd(void* arg)
{
    while (number <= MAX)
    {
        sem_wait(&odd_sem);
        printf("%d ", number++);
        sem_post(&even_sem);
    }
    return NULL;
}

void* printEven(void* arg)
{
    while (number <= MAX)
    {
        sem_wait(&even_sem);
        printf("%d ", number++);
        sem_post(&odd_sem);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&odd_sem, 0, 1);   // odd starts first
    sem_init(&even_sem, 0, 0);

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&odd_sem);
    sem_destroy(&even_sem);

    return 0;
}

