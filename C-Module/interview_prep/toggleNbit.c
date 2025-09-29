#include <stdio.h>

void togglebit(int *num, int n)
{
    int mask = 1 << n;
    *num ^= mask; 
}

void displaybit(int num)
{
    int mask;
    for(int i=31;i>=0;i--)
    {
        mask = 1 << i;
        putchar((num&mask)?'1':'0');
        if(i%8 == 0)
        putchar(' ');
    }
    printf("\n");
}

int main()
{
    int num = 10,n=2;
    displaybit(num);
    togglebit(&num,n);
    displaybit(num);
    return 0;
}
