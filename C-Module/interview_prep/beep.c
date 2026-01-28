#include <stdio.h>
#include <unistd.h>

int main()
{
    for(int i=0; i<10; i++)
    {
        printf("\a");
        fflush(stdout);
        usleep(100000);
    }

    return 0;
}
