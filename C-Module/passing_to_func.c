#include <stdio.h>
void display(char []);

int main()
{
	char s[50];
	printf("Enter string: ");
	
	fgets(s, 50, stdin);             
	
	display(s);     // Passing string c to function.    
	
	return 0;
}

//void display(char s[])   //Method1
//void display(char *s)   //Method2
{
	printf("String Output: ");
    fputs(s, stdout);
}
