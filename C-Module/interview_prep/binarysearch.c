#include <stdio.h>

int binary_search(int arr[],int size,int value){
	for(int i=0;i<size;i++){
		if(arr[i]==value)
			return i;
	}
	return 0;
}


int main(){
	int arr[] = {1,2,3,4,5,6},7,8;
	
	return 0;
}
