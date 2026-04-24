// swap 4th and 2nd number bits

#include <stdio.h>
void display(int num)
{
    int mask = 0;
    for(int i=31; i>=0; i--){
        mask = 1<<i;
        putchar((num&mask)?'1':'0');
        if(i%8==0)
        putchar(' ');
    }
    printf("\n");
}

int main()
{
    int bit = 0b10011001;
    display(bit);
    int mask1 = (bit>>1)&1;
    int mask2 = (bit>>3)&1;
    if(mask1!=mask2)
    bit^=((1<<3) | (1<<1));
    display(bit);

    return 0;
}
