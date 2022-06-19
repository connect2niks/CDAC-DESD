    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

        int main(int argc, char const *argv[])
        {
            int fd;
            fd = open("Assign1.txt", O_CREAT | O_WRONLY);

            if (fd == -1)
            {
                perror("Error occured in opening file and the error is -");
                exit(EXIT_FAILURE);
            }
            write(fd, "NIKHIL YADAV\n",13 );
            close (fd);
            
            exit(EXIT_SUCCESS);
            //return 0;
        }
        