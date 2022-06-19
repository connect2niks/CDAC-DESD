#include <stdio.h>
#include <ctype.h>
int main()
{
   int i = 0;
   char c;
   char str[] = "cdac Acts";
   while(str[i])
   {
                putchar (toupper(str[i]));
            i++;
   }
   printf("\n");
   return(0);
}

