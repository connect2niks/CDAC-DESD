// How can you store 5 bits of data inside a single character

#include <stdio.h>
int main()
{
	char a = 31;
	unsigned char b = a&0x1F;
	printf("original = %u\n",a);
	
        int mask;
        for(int i = 7; i>=0; i--)
        {
                mask = 1<<i;
                putchar((a&mask)?'1':'0');
        }
        printf("\n");

	printf("retrived  = %u\n",b);


}
