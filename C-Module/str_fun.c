#include <stdio.h> 
#include <string.h>
void main ()
 { 
char str1[12] = "Hello"; 
char str2[12] = "World"; 
char str3[12]; 
int len ;
printf("str1 : %s\n", str1 ); 
printf("str2 : %s\n", str2 ); 
 strcpy(str3, str1); 

printf("strcpy( str3, str1) : %s\n", str3 ); 
strcat( str1, str2); 
printf("strcat( str1, str2): %s\n", str1 ); 
len = strlen(str1);
 printf("strlen(str1) : %d\n", len );
 printf("sizeof(str1) : %d\n", sizeof(str1) );
}

