#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "ioctl.h"

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("/dev/niks",O_RDWR);
    if(!fd)
    {    
        perror("Error opening file\n");
        return -1;
    }
    printf("fd = %d\n",fd);

    ioctl(fd,CMD_1);
    ioctl(fd,CMD_2,8);
    return 0;
}
