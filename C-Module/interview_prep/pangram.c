//check if given string is pangram or not

#include <stdio.h>
#include <string.h>

int main(){
	
	char arr[26] = {0};
	char str[] = "The quick brown fox jumps over the lazy dog";

	for(int i=0; str[i]!='\0'; i++){
		char ch = str[i];
		if(ch >= 'A' && ch <= 'Z')
			ch = ch + ('A' - 'a');
		if(ch>='a' && ch<='z')
			arr[ch-'a'] = 1;
	}

	int pangram = 1;
	for(int i=0; i<=25; i++){
		if(arr[i] != 1)
		{
			pangram = 0;
			break;
		}
	}

	if(pangram)
		printf("Pangram\n");
	else printf("Not Pangram\n");

	return 0;

}
