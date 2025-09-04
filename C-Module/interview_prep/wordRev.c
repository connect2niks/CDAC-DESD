/*Reverse the order of words in a string, e.g., "hello world" becomes "world hello".*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reversestring(char str[],int start,int end)
{
    while(start < end)
    {
        char temp;
        temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

int main()
{
    char str[] = "hello world";
    char str2[100];
    int i,j;
    int len = strlen(str);
    reversestring(str,0,len-1);
    int start =0;
    for(int i=0; i<=len;i++)
    {
        if(str[i]==' ' || str[i] == '\0')
        {
            reversestring(str, start, i-1);
            start = i+1;
        }
    }
    printf("%s",str);
    
    return 0;
}
