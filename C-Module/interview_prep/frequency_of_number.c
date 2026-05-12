#include <stdio.h>

int main()
{
    int arr[] = {1,1,2,2,3,3,4,4,4,4,5,5,5,5,6,6,6,7,8,9,9,0,8,0,0,9,9,7,7,4};
    int hash[10] = {0};
    
    int len = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<len;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<10;i++){
        printf("%d =  %d \n",i,hash[i]);
    }

    return 0;
}
