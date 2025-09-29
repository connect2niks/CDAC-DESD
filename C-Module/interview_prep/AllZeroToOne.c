// program to convert all zeroes to one in an given number

#include <stdio.h>

int zerotoone(int num)
{
	if(num==0) return 1;
	int temp;
	int res=0,place=1;
	while(num!=0)
	{
		temp = num%10;
		if(temp == 0) temp = 1;
		res += temp*place;
		place *= 10;
	       num /=10;	
	}
	return res;
}

int main()
{
	int a = 10204;
	int res = zerotoone(a);

	printf("Original: %d\n",a);
	printf("Modified: %d\n",res);
	return 0;
}
