/* Check if a string contains only digits, e.g., "123" returns true, "12a" returns false. */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool only_digit(char s[])
{
    for(int i=0; s[i]!='\0';i++)
    {
        if(s[i]<'0'||s[i]>'9') return false;
    }
    return true;
}

int main()
{
    bool x;
    char str[] = "123a";
    x = only_digit(str);
    if(x)
    printf("True");
    else
    printf("False");
    return 0;
}
