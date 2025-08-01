#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char s1[] = "aabB";
	char s2[] = "Abba";

	if(strlen(s1)!=strlen(s2))
	{
		printf("Not Anagram");
		return 0;
	}

	int f1[26] = {0}, f2[26] = {0};

	for(int i=0; s1[i]!='\0'; i++)
	{
		f1[tolower(s1[i])-'a']++;
		f2[tolower(s2[i])-'a']++;
	}

	for(int i=0; s1[i]!='\0'; i++)
	{
		if(f1[i]!=f2[i])
		{
			printf("Not Anagram");
			return 0;
		}
	}

	printf("Anagram");
	return 0;
}
