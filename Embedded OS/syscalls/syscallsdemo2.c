    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

        int main(int argc, char const *argv[])
        {
            int fd,fd1;
            char *c = (char *) calloc(50, sizeof(char));
            fd = open("Assign1.txt", O_RDONLY);

            if (fd == -1)
            {
                perror("Error occured in opening file and the error is -");
                exit(EXIT_FAILURE);
            }
            fd1 = read(fd,c,13 );
            if (fd1 == -1)
            {
                perror("Error occured in reading file and the error is -");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("%s",c);
            }
            close (fd);
            
            exit(EXIT_SUCCESS);
            //return 0;
        }