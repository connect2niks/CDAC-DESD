#include <stdio.h>

void displaybits (unsigned int x);
unsigned int reverse(unsigned int y);
unsigned int rev(unsigned int z);

int main()
{
	unsigned int num = 0XABCD;
	printf("HEX = 0X%X\n",num);
	
	displaybits(num);
	displaybits(reverse(num));
	printf("Reverse using extract byte = 0X%X\n",rev(num));
	return 0;
}

void displaybits(unsigned int x)
{
	unsigned int mask;
	for(int i=31; i>=0; i--)
	{
		mask = 1u<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
			putchar(' ');
	}
	printf("\n");
}

unsigned int reverse(unsigned int y)
{
	unsigned int mask,rev=0;
	for(int i=0;i<32;i++)
	{
		mask = 1u<<i;
		if(y&mask)
			rev = rev|(1u<<(31-i));
	}
	return rev;
}

// using extraction

unsigned int rev(unsigned int z)
{
	unsigned int a;
	a = ((z&0X00FF)<<8)|((z&0XFF00)>>8);
	return a;
}

