#include <stdio.h>
#define my_sizeof(var) ((char*)(&var+1) - (char*)&var) // 1st method
struct stu{
    int mark;
    char name[20];
};

int main()
{
    struct stu s1;
    
    int len = (char *)(&s1 + 1) - (char *)&s1;  // 2nd method

    printf("sizeof() = %lu\n", sizeof(s1));   // 3rd method
    printf("my_sizeof() = %d\n", len);
    printf("my_sizeof() using macro = %ld\n", my_sizeof(s1));

    return 0;
}
