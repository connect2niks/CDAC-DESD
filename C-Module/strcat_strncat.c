/* Using strcat and strncat */
#include <stdio.h>
#include <string.h>

int main()
{ 
   char s1[20] = "Happy ";
   char s2[ ]  = "New Year ";
   char s3[40] = "";
   
   printf( "s1 = %s\ns2 = %s\n", s1, s2 );
   printf( "strcat( s1, s2 ) = %s\n", strcat( s1, s2 ) );
//   printf( "strncat(s3, s1, 6 ) = %s\n", strncat( s3, s1, 3 ) );
//   printf( "strcat( s3, s1 ) = %s\n", strcat( s3, s1 ) );
   return 0;
}

