#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_BUFF_SIZE 5

int main(int argc, char const *argv[])
{
    unsigned char buff[MAX_BUFF_SIZE];
   int fd[2];
   pid_t id;
   //fd[0] is for reading
   //fd[1] is for writing
    pipe(fd);
    id=fork();
    if (id==0)
    {
        close(fd[1]);
        printf("\nchild process\n");
        read(fd[0],buff,sizeof(buff));
        printf("Child: Received data: %s\n",buff);
    }
    else
    {
        close(fd[0]);
        printf("Parent process\n");
        write(fd[1],"DESD\n",5);
        printf("Parent process :wrote data \n");

    }
    
    
    return 0;
}
