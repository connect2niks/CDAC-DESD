#include <stdio.h>

int main()
{
   char str[50];

   printf("Enter a string : ");
//   scanf("%s", str);
   gets(str);

//   printf("You entered: %s", str);
 //  printf("\n");
   
   puts(str);
   printf("\n");

   return(0);
}
