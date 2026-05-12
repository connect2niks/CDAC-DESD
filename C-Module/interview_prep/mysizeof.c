#include <stdio.h>

#define mysizeof(type) (char *)(&type+1) - (char *)(&type)

int main() {
    int a;
    printf("int: %zu\n", mysizeof(a));
    return 0;
}
