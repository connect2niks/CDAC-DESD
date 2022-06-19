#include <stdio.h>
#include "arith.h"

int main(int argc, char const *argv[])
{
        int r;
        r = add(10,40);
        printf("Addition :%d\n",r);

        r = sub(40,10);
        printf("Substraction :%d\n",r);

        r = mul(10,40);
        printf("multiplication :%d\n",r);

        r = div(40,10);
        printf("Division :%d\n",r);
        
        return 0;
}


