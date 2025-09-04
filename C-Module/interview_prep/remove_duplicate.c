//Remove duplicates from a sorted array in-place, returning new length, e.g., [1,1,2] becomes [1,2].

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1,1,2,3,3,4,5};
    int u = 1;
    for(int i=1; i<7; i++)
    {
        if(arr[i]!=arr[u-1])
        {
            arr[u] = arr[i];
            u++;
        }
    }
    for(int i=0;i<u;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
