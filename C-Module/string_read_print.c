//========================
//Read and write a string
//========================

#include <stdio.h>
int main()
{
	char name[15];
	int i;
	printf("\nEnter your name: ");
	//scanf("%s", name);
	gets(name);
	//printf("\nEnter your num: ");
	//scanf("%d", &i);

	printf("\nMy Name is: %s\n\n", name);
	//printf("\nnumber is %d\n\n", i);

    return 0;
}
