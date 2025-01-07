#include <stdio.h>

int main()
{
	float ar[4] = {1.2,2.3,3.4,4.5};
	void *vp;

	vp=ar;

	for(int i = 0; i<4; i++)
	{
		printf("Array value = %lf\n",*(float *)vp + i);
	}

	return 0;
}
