#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "Hello";
    char str2[] = "world";
    int j=0;
    char str3[11];
    for(int i=0; str1[i]!='\0'; i++){
        str3[j++] = str1[i];
        str3[j++] = str2[i];
    }
    str3[j] = '\0';
    printf("%s\n",str3);

    return 0;
}
