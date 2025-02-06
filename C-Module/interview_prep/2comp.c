#include <stdio.h>
void displaybits(int x);
int main()
{
	int num,i,mask;
	printf("Enter the num : \n");
	scanf("%d",&num);
	displaybits(num);
	printf("\n");
	displaybits(~num+1);
	printf("\n");
	for(i=0; i<=31;i++)
	{
		mask=1<<i;
		if((num&mask)!=0)
			break;
	}
	for(i=i+1; i<=31;i++)
	{
		mask=1<<i;
		num = num ^ mask;
	}
	printf("Two's compliment is: \n");
	displaybits(num);
	return 0;
}

void displaybits(int x)
{
	for(int i=31; i>=0; i--)
	{
		int mask = 1<<i;
		putchar((x&mask)?'1':'0');
		if((i%8)==0)
			putchar(' ');
	}
}




