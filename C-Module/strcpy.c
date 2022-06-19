#include <stdio.h>
#include <string.h>
int main()
{
   char s[10]="CDAC",ch;
   int i,len=0;
   char d[10];

  	//strcpy(d,s); 
   for(i=0;s[i]!='\0';++i)
   {
	   d[i]=s[i];
   }
   d[i]='\0';
   printf("source string is %s \n", s);
   printf("destination string is %s \n", d);
   return 0;
}
