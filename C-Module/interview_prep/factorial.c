/*Compute the factorial of a non-negative integer, e.g., 5! = 120.*/

#include <stdio.h>
void factorial(int x)
{
    int y=1;
    for(int i=x;i>=1;i--)
        y *= i;
    printf("factorial = %d",y);
}

int main()
{
    factorial(4);
    return 0;
}
