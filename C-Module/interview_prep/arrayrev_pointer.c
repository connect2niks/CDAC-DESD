#include <stdio.h>

void rev(int *arr,int n)
{
	for(int i=0,j=n; i<n/2; i++,j--)
	{
		arr[i] = (arr[i]) ^ (arr[j-1]);
		arr[j-1] = (arr[i]) ^ (arr[j-1]);
		arr[i] = (arr[i]) ^ (arr[j-1]);
	}

	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int s;
	printf("Enter the size of array: ");
	scanf("%d",&s);
	int arr[s];
	printf("Enter the value: ");
	for(int i=0; i<s;i++)
	scanf("%d",&arr[i]);

	rev(arr,s);
	
	return 0;
}

