#include <stdio.h>
long int factorial(int n);

int main()
{
int n;
long int m;
printf("Enter any no. :");
scanf("%d",&n);
m=factorial(n);
printf("Factorial of %d is %ld\n",n,m);
return 0;
}

long int factorial(int n)
{
if (n>=1)
	return n*factorial(n-1);
else
	return 1;

}



