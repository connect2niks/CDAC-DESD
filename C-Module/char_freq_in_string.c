#include <stdio.h>
int main()
{
   char s[100],ch;
   int i,count=0;

   printf("Enter a string: ");
   gets(s);

   printf("Enter a character to find frequency: ");
   scanf("%c",&ch);

   for(i=0;s[i]!='\0';++i)
   {
       if(ch==s[i])
           ++count;
   }
   printf("Frequency of %c = %d\n", ch, count);
   return 0;
}
