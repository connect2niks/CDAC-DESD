#include <stdio.h>
#include <pthread.h>

pthread_t tid;

void *display(void *data)
{
    printf("This is thread\n");
}

int main(int argc, char const *argv[])
{
    printf("Before thread creation\n");
    pthread_create(&tid,NULL,display,NULL); // fourth arguments is for passing something to the thread
                    //second argument is for attribites of thread and giving NULL make it as joinable
    printf("After thread creation\n");
    pthread_join(tid,NULL); //second argument is for return data of thread
    return 0;
}
