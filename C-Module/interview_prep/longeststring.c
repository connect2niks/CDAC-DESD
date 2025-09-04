/*Find the longest common prefix among an array of strings, e.g., ["flower", "flow", "flight"] returns "fl".*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* longeststring(char* str[],int size)
{
    char* res;
    int len = strlen(str[0]);
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<size;j++)
        {
            if(str[j][i]!=str[0][i] || strlen(str[j])<=i)
            {
                res = (char*)malloc(i+1);
                strncpy(res,str[0],i);
                res[i] = '\0';
                return res;
            }
        }
    }

}

int main()
{
    char* str[] = {"flower","flow","flight"};
    char* res;
    res = longeststring(str,3);
    printf("%s\n",res);
    free(res);
    return 0;
}
