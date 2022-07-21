#include<stdio.h>
void bubble_sort(int [],int);

void main()
{
	int a[30],n,i;
	printf("Enter no of elements :");
	scanf("%d",&n);

	printf("Enter array elements :");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	bubble_sort(a,n);
}

void bubble_sort(int a[],int n)
{
	int i, j, k, temp;
   	printf("Unsorted Data:\t");
    	for(k=0;k<n;k++)
         	printf("%d \t",a[k]);

    	for(i=0;i< n-1;i++)
    	{
         	for(j=0;j< n-i-1;j++)
		{
         		if(a[j]>a[j+1])
              		{
               			temp=a[j];
               			a[j]=a[j+1];
               			a[j+1]=temp;
               		}
	         }
    	printf("\nAfter pass %d : ",i);
        	for(k=0 ; k< n ; k++)
             		printf("%d \t",a[k]);
		printf("\n");
    }
}
