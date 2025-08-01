#include <stdio.h>

struct stag
{
	char c;
	int i;
	float f;

};

union utag
{
	char c;
	int i;
	float f;

};

 int main()
{
	union utag uvar;
	struct stag svar;
	printf("Size of svar = %u\n",sizeof(svar));
	printf("address of svar = %p\t",&svar);
	printf("Address of members = %p %p %p\n",&svar.c,&svar.i,&svar.f);
	printf("size of uvar = %u\n",sizeof(uvar));
	printf("address of uvar = %p\t",&uvar);
	printf("Address of members = %p %p %p\n",&uvar.c,&uvar.i,&uvar.f);

	return 0;
}
