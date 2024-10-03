#include<stdio.h>

void insertionSort(int arr[],int size){
    for(int i = 1; i<size; i++){
	int temp = arr[i];
	int j = i-1;

	while(arr[j]>temp && j>=0){
	    arr[j+1]=arr[j];
	    j--;
	}
	arr[j+1]=temp;
    }
}


void printArray(int arr[],int size){
    for(int i = 0; i <size; i++){
	printf(" %d",arr[i]);
    }
}

int main(){
	int arr[] = {7,6,8,1,2,12,10,2,3};
	
	int arr_size = sizeof(arr)/sizeof(int);

	printf("Given array:\t");
	printArray(arr,arr_size);

	insertionSort(arr,arr_size);
	printf("\nSorted Array:\t");
	printArray(arr,arr_size);
	printf("\n");


	return 0;
}
