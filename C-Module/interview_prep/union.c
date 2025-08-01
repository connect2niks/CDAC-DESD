#include <stdio.h>

int main()
{
	union result
	{
		int marks;
		char grade;
		float per;
	}res;

	res.marks = 56;
	printf("Marks : %d\n",res.marks);
	res.grade = 'B';
	printf("Grade = %c\n",res.grade);
	res.per = 78;
	printf("percentage = %f\n",res.per);

	return 0;
}
