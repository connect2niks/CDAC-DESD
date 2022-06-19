#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t event_mutex;
int event=0;

void *waiting_thread(void *data)
{
    printf("Waiting Thread: Grabbing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("Waiting Thread: Got the mutex\n");
    while (event!=1)
    {
        
    }
    printf("Waiting Thread: Event is 1 so i'm done\n");
    // Actual code to do functionality.
    pthread_mutex_unlock(&event_mutex);   
    printf("Waiting Thread: Releasing the mutex\n");
}

void *fire_event_thread(void *data)
{
    printf("fire_event Thread: Grabbing the mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("fire_event Thread: Got the mutex\n");
    event=1;
    printf("fire_event Thread: Event is equal to 1\n");
    pthread_mutex_unlock(&event_mutex);
    printf("fire_event Thread: Releasing the mutex\n");
}

int main(int argc, char const *argv[])
{
    pthread_t waiting_thread_id,fire_event_thread_id;

    pthread_mutex_init(&event_mutex,NULL);
    pthread_create(&fire_event_thread_id,NULL,fire_event_thread,NULL);
    pthread_create(&waiting_thread_id,NULL,waiting_thread,NULL);
    pthread_join(waiting_thread_id,NULL);
    pthread_join(fire_event_thread_id,NULL);
    pthread_mutex_destroy(&event_mutex);
    return 0;
}
 
