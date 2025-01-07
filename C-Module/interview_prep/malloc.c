#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr,*ptr1,n;

	printf("Enter the number of element:");
	scanf("%d",&n);

	ptr = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
	{
		printf("Enter the element of array\n");
		scanf("%d",ptr+i);
	}

	for(int i=0; i<n; i++)
	{
		printf("Array element = %d\n",*(ptr+i));
	}


	ptr1 = (int *)calloc(5,sizeof(int));

	for(int i = 0;i<5;i++)
	{
		printf("value of calloc = %d\n",*(ptr1));
	}
	

	free(ptr);
	return 0;
		
}
