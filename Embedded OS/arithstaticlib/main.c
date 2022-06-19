#include <stdio.h>
#include "arith.h"

int main(int argc, char const *argv[])
{
    int result = 0;

    printf("Arith demo\n");

    result = add(10,20);
    printf("Addtion %d\n",result);
    
    result=sub(20,10);
    printf("Substraction %d\n",result);

    return 0;
    
    }
