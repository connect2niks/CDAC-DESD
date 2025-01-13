#include <stdio.h>

int main()
{
	int arr[3][4] = { {9,8,7,4},{5,6,4,1},{3,4,8,9}  };
	int (*p)[4];
	p=arr;

	*(*(p+2)+3) =*(*(p+2)+3)+1;

	printf("%d\n",*(*(p+2)+3));

	return 0;
}
