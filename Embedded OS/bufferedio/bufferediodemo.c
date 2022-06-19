# include <stdio.h>

int main(int argc, char const *argv[])
{
    int i=10;
    printf("Hello %d\n",i); //write API uses two times here because \n flushes the buffer
    printf("World");//%d,%f,%s etc. all are formate specifier 
    return 0;
}
/*
- use :-strace ./<file name>
- Library calls are buffered and formatted.
- system calls are non-buffered and non-formatted.
- if we remove \n from above printf its uses write API only one time and both strings are concatenated.
*/