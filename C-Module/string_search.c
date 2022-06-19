#include <stdio.h>
 
int main()
{
  	char s1[100], s2[100];
  	int i, j, k;
 
  	printf("\n Enter first String :  ");
  	gets(s1);
  	
	printf("\n Enter second string :  ");
  	gets(s2);
	     	   	
  	for(i = 0; s1[i] != '\0'; i++)
	{
		if(s1[i] == s2[0])
		{
			k = 1;
			for(j = 0; s2[j] != '\0'; j++)
			{
				if(s1[i + j] != s2[j])
				{
					k = 0;
					break;
				}
			}	
		}
		if(k == 1)
		{
			break;
		} 
	}
	if(k == 0)
  	{
  		printf("\n Not found '%s'\n ", s2);
	}
	else
	{
		printf("\n Found '%s' at index number %d \n", s2, i);
	}	
	
  	return 0;
}
