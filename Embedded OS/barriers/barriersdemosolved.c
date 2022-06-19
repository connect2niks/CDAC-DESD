#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_barrier_t dev_init_barrier;


void *serial_thread(void *data)
{
    printf("Serial Thread: Init Started\n");
    sleep(7); //Emulating serial port initialization and this for demo only dont use in real world.
    printf("Serial Thread: Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Serial Thread: Main functionality\n");

}

void *ether_thread(void *data)
{
    printf("Ether Thread: Init Started\n");
    sleep(10); //Emulating Ethernet port initialization and this for demo only dont use in real world.
    printf("Ether Thread: Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("Ether Thread: Main functionality\n");

}
void *lcd_thread(void *data)
{
    printf("lcd Thread: Init Started\n");
    sleep(8); //Emulating LCD initialization and this for demo only dont use in real world.
    printf("lcd Thread: Init finished\n");
    pthread_barrier_wait(&dev_init_barrier);
    printf("lcd Thread: Main functionality\n");

}
int main(int argc, char const *argv[])
{
    pthread_t serial_thread_id,ether_thread_id,lcd_thread_id;
    pthread_barrier_init (&dev_init_barrier,NULL,3); // 3 threads are their to synchronize
    pthread_create(&serial_thread_id,NULL,serial_thread,NULL);
    pthread_create(&ether_thread_id,NULL,ether_thread,NULL);
    pthread_create(&lcd_thread_id,NULL,lcd_thread,NULL);
    pthread_join(serial_thread_id,NULL);
    pthread_join(ether_thread_id,NULL);
    pthread_join(lcd_thread_id,NULL);
    pthread_barrier_destroy(&dev_init_barrier);
    return 0;
}

