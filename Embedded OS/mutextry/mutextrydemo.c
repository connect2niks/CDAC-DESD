#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
int count=0;

pthread_mutex_t mutex_count; // opaque data type variable for mutex

void *incthread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_count);
        count++;
        printf("Inc Thread: Sleeping\n");
        sleep(10);
        printf("Inc Thread: %d\n",count);
        pthread_mutex_unlock(&mutex_count);
    }      
    
}

void *decthread(void *arg)
{
    int res=0;
    while (1)
    {
        res=pthread_mutex_trylock(&mutex_count);
        printf("Result :%d\n",res);
        if(res==0)
        {
        count--;
        printf("Dec Thread: %d\n",count);
        pthread_mutex_unlock(&mutex_count);
        }
        else
        {
            // Do other functionality
        }
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
