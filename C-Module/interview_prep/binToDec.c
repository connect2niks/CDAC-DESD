#include <stdio.h>

int bintodec(int num){
    int bit=0,result=0;
    int i=1;
    while(num!=0){
        bit = num%10;
        num = num/10;
        result += bit*i;
        i = i*2;
    }
    return result;
}

int main(){
    int a = 1011;
    int b = bintodec(a);
    printf("%d\n",b);
    return 0;
}
