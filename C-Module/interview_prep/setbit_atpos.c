// program to manupulate n bits starting at pos p in a no. x, if p=7 and n=4 then the bits to be manipulated are 7th, 6th, 5th and 4th bits.

#include <stdio.h>
void displaybits(int num){
	int mask=0;
	for(int i=31; i>=0; i--){
		mask  = 1<<i;
		putchar((num&mask)?'1':'0');

		if(i%8==0)
			putchar(' ');
	}
	printf("\n");
}

int main()
{
	int p = 7, n = 4;
	int mask =0;
	int num = 34;
	mask = ~(~mask<<n)<<p-n+1;
	displaybits(num);
	num |= mask;
	displaybits(num);
	return 0;
}
