#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/in.h>

int cfd;

struct sockaddr_in saddr;

int len;
unsigned char buff[1024];

int main(int argc, char const *argv[])
{
    cfd = socket(AF_INET,SOCK_STREAM, 0);

    saddr.sin_family = AF_INET;
    saddr.sin_addr .s_addr = inet_addr("127.0.0.1");
    saddr.sin_port = htons(5678);

    connect(cfd,(struct sockaddr *)&saddr, sizeof(struct sockaddr_in));
    read(cfd, buff, 1024);
    printf("server sent: %s\n", buff);

    write(cfd,"hello from client\n",18);

    close(cfd);

    return 0;
}
