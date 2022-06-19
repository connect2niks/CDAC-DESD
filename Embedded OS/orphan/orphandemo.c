       #include <sys/types.h>
       #include <unistd.h>
       #include <stdio.h>

       int main(int argc, char const *argv[])
       {
           
        pid_t pid;

        printf("Before Fork\n");

        pid=fork();

        if (pid==0)
        {

        printf("Child Process and pid:%d , ppid: %d\n",getpid(),getppid());
        sleep(10);
        printf("Child process completed and pid:%d , ppid: %d\n",getpid(),getppid());
        }

        else if(pid>0)
        {
            printf("parent process and pid:%d , ppid: %d\n",getpid(),getppid());
            printf("Parent process completed\n");
        }
        else{
            perror("fork failed");
        }
           return 0;
       }
       

