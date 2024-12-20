#include <stdio.h>

static inline int prod(int c,int d)
{
	return c*d;
}

int main()
{
	int a,b;
	printf("Enter two number for product\n");
	scanf("%d %d",&a,&b);
	int res = prod(a,b);
	printf("product = %d",res);

	return 0;

}
