//Rotate array right by k positions, e.g., [1,2,3,4,5] with k=2 becomes [4,5,1,2,3].

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void rev(int *arr,int start,int end)
{
    int t;
    while(start < end)
    {
        t = arr[start];
        arr[start++] = arr[end];
        arr[end--] = t;
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int k=3;
    int size = sizeof(arr)/sizeof(arr[0]);

    k=k%size;    
    // reverse all
    
    rev(arr,0,size-1);

    //reverse k
    
    rev(arr,0,k-1);
    
    //reverse remain
    
    rev(arr,k,size-1);

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
