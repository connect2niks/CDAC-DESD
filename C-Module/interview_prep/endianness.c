#include <stdio.h>

int main()
{
/*	int n = 0x11223344;
	char* s = (char*)(&n);
	for(int i=0; i<=3; i++)
	printf("%x",*(s+i));
	printf("\n");

	int num = ((n&0x000000FF)<<24)|((n&0x0000FF00)<<8)|((n&0x00FF0000)>>8)|((n&0xFF000000)>>24); // This is for reverse the hex number
	printf("0X%X\n",num);
*/

	union {
		int i;
		char c[sizeof(int)];
	}test;

	test.i = 0x01020304;

	if(test.c[0] == 0X04)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return 0;
}
