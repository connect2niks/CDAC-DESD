// output = olleh123
#include <stdio.h>

int main()
{
    int count=0;
    char str[] = "Hello123";
    for(int i=0; str[i]!='\0'; i++){
        if((str[i] >= 'a' && str[i] <= 'z' ) || (str[i] >= 'A' && str[i] <= 'Z' ))
        count++;
    }
    count--;
    char temp;
    int start=0;
    while(start<count){
        str[start] = str[count] ^ str[start];
        str[count] = str[count] ^ str[start];
        str[start] = str[count] ^ str[start];
        count--;
        start++;
    }
    printf("%s",str);
    return 0;
}
