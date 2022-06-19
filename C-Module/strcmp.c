#include<stdio.h>
#include<string.h>

int main()
{
	char *str1="abc";
//	char *str2="abf";
	char *str2="abc";

	printf("%d\n", strcmp(str1, str2));

	return 0;
}
