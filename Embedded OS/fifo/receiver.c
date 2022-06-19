#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    unsigned char buff[5];

    fd=open("desdfifo",O_RDONLY);

    read(fd,buff,5);
    printf("Read data : %s\n",buff);

    close(fd);
    
    return 0;
}