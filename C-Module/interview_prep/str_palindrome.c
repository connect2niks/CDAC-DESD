//Check if a String is a Palindrome

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char str[] = "malayalam";
    for(int i=0,j=(strlen(str)-1); i<=j; i++,j--)
    {
        if(str[i] != str[j])
        {
            printf("not palindrome");
            return 0;
        }
    }
    
    printf("palindrome");
    return 0;
}
