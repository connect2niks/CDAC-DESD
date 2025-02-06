#include <stdio.h>

void displaybits (int x);
int reverse(int y);

int main()
{
	int num;
	printf("Enter an intergers\n");
	scanf("%d",&num);
	displaybits(num);
	displaybits(reverse(num));
	return 0;
}

void displaybits(int x)
{
	int mask;
	for(int i=31; i>=0; i--)
	{
		mask = 1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
			putchar(' ');
	}
	printf("\n");
}

int reverse(int y)
{
	int mask,rev=0;
	for(int i=0;i<32;i++)
	{
		mask = 1<<i;
		if(y&mask)
			rev = rev|(1<<(31-i));
	}
	return rev;
}
