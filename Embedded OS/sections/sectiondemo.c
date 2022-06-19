#include <stdio.h>

    int a;
    int b=10;

int main(int argc, char const *argv[])
{
    int result=0;
    int *p = NULL;
    p = (int *)(sizeof(int));
    add(10,20);
    return 0;
}

int add(int a, int b)
{
    return a+b;
}
