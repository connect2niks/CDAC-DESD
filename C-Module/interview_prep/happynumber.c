#include <stdio.h>

int squaredigit(int a)
{
    int x=0,z=1;
        while(a>0)
    {
        z = a%10;
        a = a/10;
        x += (z*z);
    }
    printf("%d\n",x);
    return x;
}

int main()
{
    int seen[1000] = {0};
    int ret=0,n=123;
    ret = squaredigit(n);
    while(ret>1)
    {
        if(seen[ret])
        break;
        seen[ret] = 1;
   ret = squaredigit(ret);
    }
    return 0;
}
