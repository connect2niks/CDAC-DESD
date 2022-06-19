#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
int count=0;
sem_t mecount;
void *incthread(void *arg)
{
    while (1)
    {
        sem_wait(&mecount);
        printf("Inc Thread: %d\n",count);
        count++;
        sem_post(&mecount);
    }
    
}

void *decthread(void *arg)
{
    while (1)
    {
        sem_wait(&mecount);
        printf("Dec Thread: %d\n",count);
        count--;
        sem_post(&mecount);
    }
    
}

int main(int argc, char const *argv[])
{

    pthread_t inc,dec;
    sem_init(&mecount,0,1);
    pthread_create(&inc,NULL,incthread,NULL);
    pthread_create(&dec,NULL,decthread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    sem_destroy(&mecount);

    return 0;
}
