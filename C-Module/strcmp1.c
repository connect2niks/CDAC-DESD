#include<stdio.h>
#include<string.h>

int main()
{
	char str1[10]="abc";
	char str2[10]="abc";
	printf("str 1  %s\n",str1);
	printf("str 2  %s\n",str2);
	if(strcmp(str1,str2)==0)
		printf(" str1 and str 2 are same \n");
	else
		printf(" str1 and str 2 not are same \n");

	return 0;
}
