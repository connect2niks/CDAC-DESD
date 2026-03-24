// Resource Pool (Counting Semaphore)

//Allow only 3 concurrent threads.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t resource;

void* worker(void* arg) {
    sem_wait(&resource);
    printf("Thread %ld using resource\n", (long)arg);
    sleep(2);
    printf("Thread %ld releasing resource\n", (long)arg);
    sem_post(&resource);
    return NULL;
}

int main() {
    pthread_t t[5];
    sem_init(&resource, 0, 3);

    for(long i=0;i<5;i++)
        pthread_create(&t[i], NULL, worker, (void*)i);

    for(int i=0;i<5;i++)
        pthread_join(t[i], NULL);
}

