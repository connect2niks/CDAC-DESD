#include <stdio.h>

int main(void)
{
#ifdef __STDC_VERSION__
    printf("C standard: %ld\n", __STDC_VERSION__);
#else
    printf("C90 or pre-standard C\n");
#endif
    return 0;
}

