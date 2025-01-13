#include <stdio.h>

int *func(float *p, int a);

int main()
{
	float arr[10] = {1.2,2.3,3.4,4.5,8.5,6.7,7.8,8.9,9.0,10.1};
       float *ptr;
       int n=5;
       ptr =(float *) func(arr,n);
       printf("value of *ptr = %f",*ptr);
       return 0;	       
}

int *func(float *p, int a)
{
	p = p+a;
	return p;
}
