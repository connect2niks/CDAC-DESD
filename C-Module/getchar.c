#include <stdio.h>
int main ()
{
   char c;
   int r;
   printf("Enter character: ");
   //c = getchar();
   c = getc(stdin);

   printf("Character entered: ");

   //r = putchar(c);
   r = putc(c,stdout);
   printf("\n%d\n",r);
   return(0);
}

