/* Find the second largest element in an integer array, e.g., [5,3,8,1] returns 5. */

#include <stdio.h>
int sec_largest(int x[], int y)
{
    int temp1=0,temp2=0;
    for(int i=0; i<y;i++)
    {
        if(temp1<x[i])
        {
            temp2=temp1;
            temp1 = x[i];
        }
        else if (x[i] > temp2 && x[i] != temp1)
        {
            temp2 = x[i];
        }
    }
    return temp2;
}

int main()
{
    int arr[] = {10,11,5,10,3};
    int y = sizeof(arr)/sizeof(arr[0]);
    int z = sec_largest(arr,y);
    printf("second largest in given array = %d\n",z);
    return 0;
}
