//Merge two sorted arrays into the first array,
//which has enough space, e.g., [1,3,0,0] and [2,4] becomes [1,2,3,4].

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void arraysorting(int *a1, int m, int *a2, int n)
{
    int i = m-1, j=n-1, k = m+n-1;
    while(i>=0 && j>=0)
    {
        a1[k--] = (a1[i] > a2[j])?a1[i--]:a2[j--];
    }
    
    while(j>=0)    // copy remaining
    a1[k--] = a2[j--];
    
    for(int i=0; i<6; i++)
    {
        printf("%d ",a1[i]);
    }
}

int main()
{
    int a1[] = {9,11,0,0,0}, a2[] = {2,5,6,8};
    arraysorting(a1,2,a2,4);

    return 0;
}
