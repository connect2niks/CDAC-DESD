//========================
//Read and write a string
//========================
#include <stdio.h>
int main()
{
        char name[15];
        printf("\nEnter your name: ");
        //scanf("%s", name);
        gets(name);

        printf("\nMy Name is: %s\n\n", name);
        puts(name);

    return 0;
}

