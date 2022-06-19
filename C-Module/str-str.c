#include <stdio.h>
#include <string.h>


int main () {
   const char mains[20] = "cdac acts course";
   const char sub[10] = "acts1";
   char *ret;

   ret = strstr(mains, sub);
	if(ret != NULL)
   printf("The substring %s  is present in the main string  %s\n", sub,mains);
	else
   printf("The substring %s  is not present in the main string  %s\n", sub,mains);
   
   return(0);
}
