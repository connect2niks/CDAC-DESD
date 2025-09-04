/* Find the first occurrence of a substring (needle) in a string (haystack), returning a pointer to the start or NULL if not
found, e.g., strstr("hello", "ll") returns pointer to "ll"*/

#include <string.h>
#include <stdio.h>

char* mystrstr(char* str1, char* str2)
{
    if(str1==NULL || str2==NULL) return (char *)str1;
    for(int i=0; str1[i]!='\0'; i++)
    {
        int j=0;
        while(str2[j]!='\0' && str1[i+j]==str2[j]) j++;
        if(str2[j]=='\0') return (char*) &str1[i]; 
    }
    return NULL;
}

int main()
{
    char str1[] = "hello nikhil yadav";
    char str2[] =  "\0";
    char* p = mystrstr(str1, str2);
    if((char*) p == NULL) printf("string not found");
    else printf("%s",p);
    
    return 0;
}
