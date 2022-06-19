#include <stdio.h>

int main ()
{
   char c[5];
   int r;
	int i;
   for(i=0;i<=4;i++)
	{ 
   printf("Enter character: ");
   c[i]=getc(stdin);

   getc(stdin);
	}
		   
   printf("Characters entered: ");

   for(i=0;i<=4;i++)
	{ 
    putchar(c[i]);

   //printf("\n%d\n",r);
	}

   return(0);
}
