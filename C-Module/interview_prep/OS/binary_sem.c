#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* taskA(void* arg) {
    printf("Task A done\n");
    sem_post(&sem);
    return NULL;
}

void* taskB(void* arg) {
    sem_wait(&sem);
    printf("Task B starts after A\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&sem, 0, 0);

    pthread_create(&t2, NULL, taskB, NULL);
    pthread_create(&t1, NULL, taskA, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

