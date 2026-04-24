#include <stdio.h>

int add(int a, int b){
	return a+b;
}

int main(){
	
	int (*fptr)(int, int);

	fptr = add;

	printf("%d\n",fptr(2,4));

	return 0;
}
