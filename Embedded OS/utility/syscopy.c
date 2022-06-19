#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define size 1000

int main(int argc, char const *argv[])
{
    int fdr, fdw;
    char buf[size];

    if (argc > 3)
    {
        printf("More then two files are not allowed\n");
        exit(EXIT_FAILURE);
    }

    fdr = open(argv[1], O_RDONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);

    if (fdr == -1)
    {
        perror("Error occured in opening file 1 and the error is -\n");
        exit(EXIT_FAILURE);
    }

    fdw = open(argv[2], O_CREAT | O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
    if (fdw == -1)
    {
        perror("Error occured in opening file 1 and the error is -\n");
        exit(EXIT_FAILURE);
    }

    while (read(fdr, &buf, size)!= 0)
    {
       write(fdw, &buf, size);
      }
    close(fdr);
    close(fdw);
    exit(EXIT_SUCCESS);
}