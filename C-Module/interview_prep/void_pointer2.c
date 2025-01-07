#include <stdio.h>

int main()
{
	int a = 23;
	float b = 3.5 ,*fp = &b;

	void *vp = &a;

	printf("Value of a = %d\n" ,*(int *)vp);

	*(int *)vp = 65;

	printf("Value of a = %d\n" ,*(int *)vp);

	vp = fp;


	printf("Value of b = %lf\n" ,*(float *)vp);

	return 0;


}
