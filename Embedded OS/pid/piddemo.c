#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid_t ppid;
    pid=getpid();
    printf("pid : %d \n",pid);

    ppid=getppid();
    printf("ppid %d \n",ppid);
    
    return 0;
}
