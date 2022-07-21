#include<stdio.h>

void quick(int arr[],int s,int e);
int partition(int arr[],int s,int e);
//int swap(int *x,int *y);



void main()
{
	int n,arr[100];
	printf("Enter the size of the array");
	scanf("%d",&n);
	printf("Enter the elements of array:");
	for(int i=0;i<n;i++)
	{
		scanf("%4d",&arr[i]);
	}

	printf("Original array:");

	for(int i=0;i<n;i++)
	{
		printf("%4d",arr[i]);
	}
	printf("\n");
	quick(arr,0,(n-1));
	
	printf("Sorted array:");

	for(int i=0;i<n;i++)
	{
		printf("%4d",arr[i]);
	
	}
	printf("\n");

}

void quick(int arr[],int s,int e)
{
	int j;
	if (s<e)
	{
		j=partition(arr,s,e);
		quick(arr,s,j-1);
		quick(arr,j+1,e);
	
	}

}

int partition(int arr[],int s,int e)
{
	int i,j,p;
	i=s;
	j=e;
	p=arr[s];
	while(i<j)
	{
	while(arr[i]<=p)
		i++;

	while(arr[j]>p)
		j--;

	if (i<j)
	{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;

	}
	}

		int temp=arr[s];
		arr[s]=arr[j];
		arr[j]=temp;
	

	return j;
}

