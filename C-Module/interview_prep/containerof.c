#include <stdio.h>
#define offset(type,member)  (long)(&((type *)0)->member)
#define containerof(ptr,type,member)   ((type *)  ((char *)ptr - offset(type,member)))   

struct ajay{
    int a;
    char b;
}aj;
int main() {
   
    printf("%d\n",offset(struct ajay, b));
    char *ptr = &aj.b;
    printf("%p\n",containerof(ptr,struct ajay,b));
    printf("%p\n",&aj);
    return 0;
}
