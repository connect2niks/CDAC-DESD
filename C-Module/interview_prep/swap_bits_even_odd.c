#include <stdio.h>
void displaybits(unsigned int a){
    int mask;
    for(int i=7; i>=0; i--){
        mask = 1<<i;
        putchar((a&mask)?'1':'0');
    }
    printf("\n");
}
int main()
{
    unsigned int a = 0b10101010;
    displaybits(a);
    a = ((a&0X55)<<1)|((a&0XAA)>>1);
    displaybits(a);
    return 0;
}
