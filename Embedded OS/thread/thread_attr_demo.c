#include <stdio.h>
#include <pthread.h>
pthread_attr_t attr;
pthread_t tid;

void *display(void *data)
{
    printf("This is thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_attr_init(&attr); // Default Attribute

    // Set Attributes - Thread detach state
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

    printf("Before thread creation\n");
    pthread_create(&tid,&attr,display,NULL); // fourth arguments is for passing something to the thread
                    //second argument is for attribites of thread and giving NULL make it as joinable
    pthread_attr_destroy(&attr);
    printf("After thread creation\n");
    pthread_join(tid,NULL); //second argument is for return data of thread
    return 0;
}
