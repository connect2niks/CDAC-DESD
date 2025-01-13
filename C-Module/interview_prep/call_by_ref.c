#include<stdio.h>
void func(int x,int y,int *ps,int *pd,int *pp);
int main()
{
	int a=2,b=3,sum,diff,prod;

	func(a,b,&sum,&diff,&prod);
	printf("sum = %d, diff = %d, prod = %d",sum,diff,prod);
}

void func(int x,int y,int *ps,int *pd,int *pp)
{
	*ps = x+y;
	*pd = x-y;
	*pp = x*y;
}

