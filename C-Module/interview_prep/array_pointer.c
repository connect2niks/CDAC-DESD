#include <stdio.h>

int main()
{
	int *p;
	int (*ptr)[5];
	int arr[5] = {15,26,34,47,85};

	p = arr;
	//p++;
	printf("p+1 = %d",*(p+1));

	ptr = &arr;

	printf("ptr+1 = %d",*(*ptr+1));

}
