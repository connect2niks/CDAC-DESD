#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count=0;
pthread_rwlock_t count_rwlock;

void *reader1(void* data)
{
    int z;
    printf("Reader 1:Entering critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader 1: Inside critical section\n");
    z=count+10;
    printf("Reader 1 :%d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader 1: Left critical section\n");
}

void *reader2(void* data)
{
    int x;
    printf("Reader 2:Entering critical section\n");
    pthread_rwlock_rdlock(&count_rwlock);
    printf("Reader 2:Inside critical section\n");
    x=count+20;
    printf("Reader 2 :%d\n",count);
    pthread_rwlock_unlock(&count_rwlock);
    printf("Reader 2: Left critical section\n");    
}

void *writer(void* data)
{
    printf("Writer:Entering critical section\n");
    pthread_rwlock_wrlock(&count_rwlock);
    printf("Writer:Inside critical section\n");
    count++;
    pthread_rwlock_unlock(&count_rwlock);
    printf("Writer : Left critical section\n");

}


int main(int argc, char const *argv[])
{
    pthread_t r1,r2,w;
    pthread_rwlock_init(&count_rwlock,NULL);
    pthread_create(&r1,NULL,reader1,NULL);
    pthread_create(&r2,NULL,reader2,NULL);
    pthread_create(&w,NULL,writer,NULL);
    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w,NULL);
    pthread_rwlock_destroy(&count_rwlock);
    return 0;
}
