#include <stdio.h>

void inorder();
void preorder();
int right(int x);
int left(int x);

int a[100],n;
int main()
{

	printf("Enter the size of the array :");
	scanf("%d",&n);

	printf("\nEnter the elements of the array");
	printf("\n\nElement [1] :");
	scanf("%d",&a[0]);
	for (int i=2;i<n+1;i++)
	{
	printf("Element [%d]:",i);
	scanf("%d",&a[i-1]);
	}

	printf("\nInorder traverse :\n");

	inorder(0);

	printf("\n");

	printf("\nPreorder traverse :\n");

	preorder(0);

	printf("\n\n");
	return 0;



}


int right(int x)
{
	if(a[x]!=0 && ((2*x)+2)<=n)
		return (2*x)+2;
	return -1;
}

int left (int x)
{
	if(a[x]!=0 && ((2*x)+1)<=n)
		return (2*x)+1;
	return -1;
}

void inorder (int x )
{
	if (x>=0 && a[x]!= 0)
	{
		inorder(left(x));
		printf("%4d",a[x]);
		inorder(right(x));
	}

}

void preorder(int x)
{ 
	if(x>=0 && a[x]!=0)
	{
	printf("%4d",a[x]);
	preorder(left(x));
	preorder(right(x));
	}
}
