#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>           
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int *count=NULL;
int main(int argc, char const *argv[])
{
    /* O=rw- G=rw- w=---  #0660 */
    int shmfd;
    sem_t *countsem;
    countsem = sem_open("/desdsem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP,1); 

    shmfd=shm_open("/desdshm",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
    if (shmfd==-1)
    {
        perror("Unable to create shared memory");
        return EXIT_FAILURE;
    }

    ftruncate(shmfd,sizeof(int));

    count=(int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shmfd,0);

    while (1)
    {
        //lock
        sem_wait(countsem);
        printf("%d\n",*count);
        sem_post(countsem);
        //unlock
    }

    sem_close(countsem);

        
    return 0;
}


