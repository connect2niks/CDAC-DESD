// for set alternate bit
#include <stdio.h>

void displaybits(int a)
{
    int mask;
    for(int i=31; i>=0; i--)
    {
        mask = 1<<i;
        putchar(a&mask?'1':'0');
        if(i%8==0)
        putchar(' ');
    }
    printf("\n");
}
int togglebits(int a)
{
    int mask;
    for(int i=1; i<32; i-=2)
    {
        mask = 1<<i;
        if((a&mask)==0)
        a |= (1 << i);
    }
    return a;
}

int main()
{
    int a = 45;
    displaybits(a);
    int b = togglebits(a);
    displaybits(b);
    return 0;
}
