#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "eeeet";
    int i,j,count;
    
    for(i=0; strlen(s);i++)
    {
        count =0;
        for(j=0; j<strlen(s); j++)
        {
            if(i!=j && s[i]==s[j])
           {
               count++;
               break;
           }
        }
        if(count==0)
        {
            printf("%c",s[i]);
            return 0;
        }
    }
    return 0;
}
