#include <stdio.h>
#include <string.h>
char* rev(char str1[]);
int len;
char str[100];
int main()
{
	char *ptr;
	printf("Enter the string:\n");
	gets(str);
	ptr = rev(str);
//	printf("length = %d",len);
	for(int i=0; i<len+1;i++)
	{
	//	printf("%c",*ptr);
	//	ptr++;
	}
	
	return 0;
}

char* rev(char str1[])
{
	static char str2[100];
	char *p,*p1,*p2 ;
	for(int i = 0;str1[i]!='\0'; i++ )
	{
		len=i+1;
	}


/*****************Palindrome with using  second string*****************

	for(int i =len-1,j=0 ; i>=0; i--,j++)
	{
		str2[j] = str1[i]; 
	}
	int count=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str2[i]!=str1[i])
			count++;
	}
	if(count == 0)
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");
	
************************************************************************/

/*****************palindrome**********************************************

	int count =0;
	for(int i=0,j=len-1; i<j; i++,j--)
	{
		if(str1[i] != str1[j])
			count++;
	}

	if(count == 0)
		printf("Palindrome\n");
	else
		printf("Not palindrome\n");
*****************************************************************************/

/****************reverse print*************************
	
	char x;	
	for(int i=len-1;i>=0;i--)
	{
		x = str[len-1];
		printf("%c",x);
		len--;
	}


***************************************************/

//		printf("len = %d\n",len);


/************ reverse whole sentence without reverse word ****************
	
	for(int i = len-1; i>=0; i--)
	{
		if(str1[i] == ' ' || i==0 )
		{
			printf("%s ",&str1[i==0?i:i+1]);
			str1[i] = '\0';
		}
	}
	printf("\n");
***********************************************************************/

/**************save above reverse sentence into a string *************

	int pos=0;
	int end = len;
	for(int i = len -1;i>=0;i--)
	{
		if(str1[i]==' ' || i == 0)
		{
			int start = (i==0)?i:i+1;
			for(int k=start; k<end;k++)
			{
				str2[pos++] = str1[k];
			}
			str2[pos++] = ' ';
			end = i;
		}
	}
	str2[pos-1] = '\0';

	printf("%s",str2);

********************************************************************/



/******without using second string ********************

	for(int i =0,j=len-1; i<=j;i++,j--)
	{
		char tmp;
		tmp = str1[i];
		str1[i] = str1[j];
		str1[j] = tmp;
		
	}

****************************************************/

/************using second string********************	
	for(int i=len-1,j=0; i>=0 ; i--,j++)
	{
		str2[j] = str1[i];
	}
	
*******************************************************/

/************* using two pointer***********************
        p1 = str1;
        p2 =&str1[len-1];
 
	while(p1<p2)
	{
//	p1 = str1;
//	p2 =&str1[len-1];
	char tmp;
	tmp = *p1;
	p1 = p2;
	*p2 = tmp;
	p1++;
	p2--;
	}

**************************************************/

	for(int i=0; i<len;i++)
        {
  //              printf("%c",str2[i]);
        }

	p = str1;
	return p;
}
