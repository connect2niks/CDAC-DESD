/*Replace all spaces in a string with "%20" in-place, assuming sufficient space, e.g., "hello world" becomes
"hello%20world".*/

#include <string.h>
#include <stdio.h>

int main()
{
    char str[100] = "nikhil yadav ";
    int len = strlen(str);
    int count=0;
    for(int i=0; str[i]!='\0'; i++)
    {
         if(str[i] == ' ')
         count ++;
    }
    
    printf("spaces = %d\n",count);
       
    int newlen = len + 2 * count;
    str[newlen] = '\0';
    
    for(int i=len-1,j=newlen-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else
        {
            str[j--] = str[i];
        }
    }
    
    printf("%s",str);
    return 0;
}
