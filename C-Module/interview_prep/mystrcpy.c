/*Copy a source string to a destination, including '\0', e.g., copy "hello" to new buffer.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mystrcpy(char str1[],char str2[])
{
    int i;
    for(i=0; str1[i]!='\0';i++)
    {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    
}
int main()
{
    char str1[100] = "nikhil yadav";
    char str2[100];
    mystrcpy(str1,str2);
    printf("%s",str2);
    return 0;
}
