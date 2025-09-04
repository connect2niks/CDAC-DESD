/* Sort an integer array using bubble sort, e.g., [5,2,8] becomes [2,5,8]. */

#include <stdio.h>

int main()
{
    int arr[] = {9,0,4,5,1,6,3,6,4,7};
    int n  = sizeof(arr)/sizeof(arr[0]);
    printf("size of array = %d \n",n);
    for(int i=0; i<n-1;i++)
    {
        int temp;
        for(int j=0; j<(n-i)-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
