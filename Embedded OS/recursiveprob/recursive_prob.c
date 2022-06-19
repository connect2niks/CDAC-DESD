#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
int count=0;

pthread_mutex_t mutex_count; // opaque data type variable for mutex

void *incthread(void *arg)
{
    while (1)
    {
        printf("IncThread :Locking 1st time\n");
        pthread_mutex_lock(&mutex_count);
        printf("IncThread :Locking 2nd time\n");
        pthread_mutex_lock(&mutex_count);
        printf("IncThread : changing count\n");
        count++;
        printf("Inc Thread: %d\n",count);
        pthread_mutex_unlock(&mutex_count);
        printf("IncThread :Unlocked 1st time\n");
        pthread_mutex_unlock(&mutex_count);
        printf("IncThread :Unlocking 2nd time\n");

    }      
    
}

void *decthread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_count);
        printf("Dec Thread: %d\n",count);
        count--;
        pthread_mutex_unlock(&mutex_count);
    }
    
}

int main(int argc, char const *argv[])
{
    pthread_t inc,dec;
    
    pthread_mutex_init(&mutex_count,NULL);  // mutex initialise

    pthread_create(&inc,NULL,incthread,NULL);
    pthread_create(&dec,NULL,decthread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    
    pthread_mutex_destroy(&mutex_count); // mutex destroy

    return 0;
}
