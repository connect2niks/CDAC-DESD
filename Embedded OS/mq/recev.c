#include <fcntl.h> 
#include <sys/stat.h>        
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_SIZE 128

struct mq_attr attr;
mqd_t mqd;
unsigned char buff[MAX_SIZE]; 
unsigned int prio; 
int main(int argc, char const *argv[])
{
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;

    mqd = mq_open("/desdmq",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,&attr);

    if (-1==mqd)
    {
        perror("msg queue not created");
        return EXIT_FAILURE;        
    }

    mq_receive(mqd,buff,MAX_SIZE,&prio);
    printf("msg buffer : %s\n",buff);

    mq_close(mqd);
    
    return 0;
}
