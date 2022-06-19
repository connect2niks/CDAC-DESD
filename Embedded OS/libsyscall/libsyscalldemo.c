#include <stdio.h>
char str[] = "Niks";
int main(int argc, char const *argv[])
{
    int a;
    int b;
    printf("Enter any number :");
    scanf("%d",&a);


    printf("Nikhil Yadav \n");
    b=strlen(str);
    printf("String length of Niks= %d \n\n",b);
//use "strace ./libsyscalldemo" on terminal - for trace system calls
    return 0;
}
