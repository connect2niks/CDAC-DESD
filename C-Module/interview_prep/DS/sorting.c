#include <stdio.h>
#define SIZE   10 

/* Printing Error */

void printarr(int arr[]){
	for(int i=0; i<SIZE; i++){
	printf("%d, ",arr[i]);
	}
}

/* Bubble Sort */

void bubblesort(int arr[]){
	printf("Bubble Sort: \n");
	for(int i=0; i<SIZE-1; i++){
		int f=1;
		for(int j=0; j<SIZE-i-1; j++){
			if(arr[j]>arr[j+1]){
				f = 0;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(f){
			printf("No. of Iterations: %d \n",i);
			break;
		}
	}
	printarr(arr);
}

/* Insertion Sort */

void insertionsort(int arr[]){
	printf("Insertion Sort: ");
	int temp;
	for(int i=1; i<SIZE; i++){
		temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]<temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	printarr(arr);
}

/* Selection Sort */

void selectionsort(int arr[]){
	printf("Selection Sort: ");
	int min = 0;
	for(int i=0; i<SIZE-1; i++){
		min = i;
		for(int j=i+1; j<SIZE; j++){
			if(arr[j]<arr[min])
				min = j;
		}
		if(min!=i){
			int t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
	}
	printarr(arr);
	
}

/* Quick Sort  */

void quicksort(int arr[]){
	printf("Quick Sort: ");


}

/* Merge Sort  */

void merge(int arr[],int temp[], int lb, int mid, int ub){
	int i=lb,j=mid+1,k=lb;
	while(i<=mid && j<=ub){
		if(arr[i]<arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=ub)
		temp[k++] = arr[j++];

}

void copy(int arr[], int temp[], int lb, int ub){
	for(int i=lb; i<=ub; i++)
		arr[i] = temp[i];
}
void mergesort(int arr[], int lb, int ub){
	int mid=0;
	int temp[SIZE];
	if(lb<ub){
		mid = (lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,temp,lb,mid,ub);
		copy(arr,temp,lb,ub);
	}	
}

/* main function */

int main(){
	int arr[SIZE] = {0,1,2,3,4,5,6,7,9,8};
	printf("Unsorted array: ");
	for(int i=0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");

//	bubblesort(arr);
//	printf("\n");
	
//	insertionsort(arr);
//	printf("\n");
	
//	selectionsort(arr);
//	printf("\n");
	
	quicksort(arr);
	printf("\n");
	
//	mergesort(arr, 0, SIZE-1);
//	printf("Merge sort: ");
//	printarr(arr);
//	printf("\n");
	
	return 0;
}
