#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    int op_result;

    printf("Welcome to read app\n");
    fd = open("/dev/read_app", O_RDWR, 0777);

    if (fd<0)
    {
        printf("error in opening file\n");
        return -1;
    }

    printf("Success in opening file\n");

    int result = read(fd, &op_result, sizeof(op_result));

    if (result < 0)
    {
        printf("Error in reading data from kernel to user\n");
        return -1;
    }
    close(fd);

}