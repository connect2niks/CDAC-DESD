#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char s[] = "-9045163647";
    int sign=1;
    long result = 0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i] == '-')
        {
        sign = -1;
        i++;
        }
        result = result * 10 + (s[i]-48);
    }
    result = (sign * result);
    printf("%ld",result);
    
    return 0;
}
