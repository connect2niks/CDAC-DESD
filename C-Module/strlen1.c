#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //char str[20] = "CDAC\nACTS";
    char str[20] = {'C','D','A','C',' ','A','C','T','S'};
	int i=0;
	int length=0;
	while(str[i]!='\0')
	{
		length++;
		i++;
	}
		
	
	printf("Length of string: %d\n",length);
    return 0;
}
