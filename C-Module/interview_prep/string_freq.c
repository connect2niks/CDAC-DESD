// count frequency of each character in the string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int len;
	char ch;
	char *p = NULL;
	printf("Enter the length of  the string:\n");
	scanf("%d",&len);
	char str[len];
//	p = (char *)malloc(len*(sizeof(char)));
	printf("Enter the string:\n");
	scanf("%s",str);
	int n = strlen(str);

	for(int i =0;i<n;i++)
	{
		if(str[i]!=0)
		{
		ch = str[i];
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(ch == str[j])
			{
				count++;
				str[j] = 0;
			}
		}
		printf("%c freq = %d\n",ch,count);
		}

		//printf("%c",*p);
	}

	//printf("%s\n",p);
}
