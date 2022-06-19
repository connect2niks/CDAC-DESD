#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
//    char s1[3], s2[3], i, j;
    char s1[100], s2[100], i, j;

	printf("Enter first string: ");
    scanf("%s",s1);
    
	printf("Enter second string: ");
    scanf("%s",s2);
    
//	for(i=0; s1[i]!='\0'; ++i);  /* i contains length of string s1. */

/*	    for(j=0; s2[j]!='\0'; ++j, ++i)
		    {
	        	s1[i]=s2[j];
		    }
		    s1[i]='\0';
*/
	strcat(s1,s2);
	
	printf("After concatenation: %s",s1);
	printf("\n");
	return 0;
}
