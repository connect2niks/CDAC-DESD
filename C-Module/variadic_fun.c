#include <stdio.h>
#include <stdarg.h>

int sum(int a, ...)
{
	int value=0,tot=0;
	va_list ap;
	va_start(ap,a);
	for (int i=0;i<a;i++)
	{
		value = va_arg(ap,int);
		tot = tot+value; 
	}	

	printf("sum = %d\n",tot);

	va_end(ap);
	return 0;
}

int main()
{
	sum(5,4,5,6,7,8);
	sum(4,1,1,1,1);
	return 0;
}
