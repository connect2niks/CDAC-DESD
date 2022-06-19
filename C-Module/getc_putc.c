#include<stdio.h>

int main()
{
	char c;
	printf("Enter character: ");
	c=getc(stdin);
	
	printf("Character entered: ");
	putc(c,stdout);

	printf("\n");
	return(0);
}
