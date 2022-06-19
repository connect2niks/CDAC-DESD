#include <stdio.h>
int main()
{
    char s1[100], s2[100], i;
    printf("Enter string s1: ");
    scanf("%s",s1);

	//Copy character by character
    for(i=0; s1[i]!='\0'; ++i)
    {
	    s2[i]=s1[i];
	}
	
	s2[i]='\0';
	printf("String s2: %s\n",s2);
	return 0;
}
