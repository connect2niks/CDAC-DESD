#include<stdio.h>
void displaybits(int x);
void mul(int a);
void div(int b);
void count1s(int x);
void swap(int *x,int *y);
void even_odd(int x);
void clear_rightmost(int x);

int main()
{
	int a,b;
	printf("Enter the values of a and b in hexadecimal:");
	scanf("%x%x",&a,&b);
printf("*****************a bits representation******************\n");
	printf("a = %X\n",a);
	displaybits(a);
printf("*****************b bits representation******************\n");
	printf("b = %X\n",b);
        displaybits(b);
printf("****************logical AND******************\n");
	printf("a&b = %X\n",a&b);
        displaybits(a&b);
printf("*****************Even Odd******************\n");
	even_odd(a);

printf("***************** count 1's ******************\n");
	count1s(a);
printf("*****************Multiplication*****************\n");
	mul(a);
printf("*****************Division******************\n");
        div(b);
printf("*****************clear rightmost******************\n");
	clear_rightmost(a);
printf("*****************Swapping******************\n");
	swap(&a,&b);
	printf("After swapping a = %X, b = %X\n",a,b);
}

void displaybits(int x)
{
	int mask;
	for(int i = 31; i>=0; i--)
	{
		mask = 1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
			putchar(' ');
	}
	printf("\n");
}

void mul(int a)
{
        a = a<<2;
        printf("Multiplication by 4 (a) = %X\n",a);
        displaybits(a);
}

void div(int b)
{
	 b = b>>2;
        printf("division by 4 (b) = %X\n",b);
        displaybits(b);

}

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void even_odd(int x)
{
	int mask = 0x01;
	if((x&mask)==0)
		printf("a is even\n");
	else
		printf("a is odd\n");
}
void clear_rightmost(int x)
{
	displaybits(x);
	x = x&(x-1);
	displaybits(x);

}

void count1s(int x)
{
	int count=0,mask;
	for(int i=0;i<32;i++)
	{
		mask = 1<<i;
		if((x&mask)!=0)
			count++;
	}
	printf("1's count  = %d\n",count);

}
