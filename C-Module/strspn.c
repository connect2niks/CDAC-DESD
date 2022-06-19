#include <stdio.h>
#include <string.h>
int main () {
   int len; 
   const char str1[] = "abcdefgh"; 
   const char str2[] = "abXXcdeZZh";
   /* Searching the string str2 in the string str1.
    * It returns the count of characters of str2 that
    * are matched in the str1 
    */
   len = strspn(str1, str2);
   printf("Number of matched characters: %d\n", len );
   return 0;
}
