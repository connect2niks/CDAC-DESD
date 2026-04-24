#include <stdio.h>

int add (int a,int b){ return (a+b); }
int mul (int a, int b){ return (a*b); }

int operate(int a, int b, int(*op)(int, int)){
	return op(a,b);
}
int main(){
	printf("ADD: %d\n",operate(2,3,add));
	printf("MUL: %d\n",operate(2,3,mul));
	return 0;
}
