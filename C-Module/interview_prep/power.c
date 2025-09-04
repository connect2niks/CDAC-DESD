/*Compute x raised to power n, e.g., 2^3 = 8.*/

#include <stdio.h>
int power(int x, int y)
{
    if(y==0) return 1;
    int z=1;
    for(int i=1; i<=y;i++)
    z *= x;
    return z;
}

int main()
{
    int x=-2,y=2,z;
    z = power(x,y);
    printf("%d",z);
    return 0;
}
