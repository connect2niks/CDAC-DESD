#include <stdio.h>
void registerfun(int);
void staticfun();
void autofun(int);
int main()
 {
	 register int j=1;
     extern int m;
      	 auto int n=1 ;
      printf("Output for auto stoage class\n");
       	autofun(n);
      printf("value is %d\n",n);
        autofun(n);
      printf("value is %d\n",n);
       printf("Output for static storage class\n");

      staticfun();
      staticfun();

      printf("Output for Extern storage class\n");

      printf("value of m is %d\n",m);

      printf("Output for register storage class\n");
      registerfun(j);
      registerfun(j);

}

void autofun(int n)
{
      n++;
      printf("value is %d\n",n);
}

void staticfun()
{
static int i=0;
i++;


printf("value is %d\n",i);

}

int m=100;


void registerfun(int j)
{

j++;
printf("value is  %d\n",j);

}
