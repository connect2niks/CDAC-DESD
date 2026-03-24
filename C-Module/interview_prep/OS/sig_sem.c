#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t event;

void* task(void* arg) {
    while(1) {
        sem_wait(&event);
        printf("Event handled\n");
    }
}

void* isr_sim(void* arg) {
    while(1) {
        sleep(2);
        printf("Interrupt occurred\n");
        sem_post(&event);
    }
}

int main() {
    pthread_t t1, t2;
    sem_init(&event, 0, 0);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, isr_sim, NULL);

    pthread_join(t1, NULL);

    return 0;
}

