// Check if a number is a power of 2 (e.g., 4, 8, 16), e.g., 16 returns true, 10 returns false.

#include <stdio.h>

void checkpoweroftwo(int num)
{
    if(num > 0 && (num & (num-1))==0)
    printf("True\n");
    else 
    printf("False\n");
}

int main()
{
    int num = 0;
    checkpoweroftwo(num);
    return 0;
}
