#include <stdio.h>
#include <string.h>

	struct sandbox
	{
		char employee[20];
		int emp_id;
		char domain[20];
	}sb[4];

int main()
{

//	struct sandbox sb[4];
	struct sandbox *ptr = sb;  // pointers to structures

	                for(int i=0; i<4; i++)
        {
                printf("%s %d %s\n",(ptr+i)->employee,(ptr+i)->emp_id,(ptr+i)->domain);
        }

	for(int i=0; i<4; i++)
	{
	printf("Enter Employee_Name, Employee-id, Domain\n");
	scanf("%s%d%s",(*(sb+i)).employee,&(ptr+i)->emp_id,(ptr+i)->domain);
	}

	for(int i=0; i<4; i++)
	{
		printf("%s %d %s\n",(ptr+i)->employee,(ptr+i)->emp_id,(ptr+i)->domain);
	}

	memset(&sb[3],0,sizeof(sb[1]));

	        for(int i=0; i<4; i++)
        {
                printf("%s %d %s\n",(ptr+i)->employee,(ptr+i)->emp_id,(ptr+i)->domain);
        }

	return 0;
}
