#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    int num1,num2;

    printf("Welcome to write app1\n\n Enter two numbers for addition:");
    scanf("%d %d",&num1,&num2);

    int number[2] = {num1,num2};

    fd = open("/dev/write_app1", O_RDWR, 0777);

    if (fd<0)
    {
        printf("error in opening file\n");
        return -1;
    }

    printf("Success in opening file\n");

    int result = write(fd, &number, sizeof(number));

    if (result < 0)
    {
        printf("Error in writing from user to kernel\n");
        return -1;
    }

}