#include <stdio.h>
int main ()
{
int i;
char name[10] = {'A', 'C', 'T','S','D','E','S','D','\0'}; 
printf("message: %s\n", name );  

for(i=0;i<10;i++)
{
printf("message : %c  .. %d \n", name[i],name[i] );  
}



/*
printf("message : %c  .. %d \n", name[0],name[0] );  
printf("message : %c  .. %d \n", name[1],name[1] );  
printf("message : %c  .. %d \n", name[2],name[2] );  
printf("message : %c  .. %d \n", name[3],name[3] );  
printf("message : %c  .. %d \n", name[4],name[4] );  
*/



//printf("message: %d\n", sizeof(name) );  
return 0;
}


