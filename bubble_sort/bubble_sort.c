#include<stdio.h>
#include<stdbool.h>


void printArray(int arr[],int size){
    for(int i =0;i<size;i++){
	printf(" %d",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int size){
    bool swapped;
    for(int i = 0; i<size;i++){
	swapped=false;
	for(int j = 0;j<size-1-i;j++){
	    if(arr[j]>arr[j+1]){
		swap(&arr[j],&arr[j+1]); 
		swapped = true;
	    }
	}
	if(!swapped){
	    break;
	}
    }

}

int main(){
    int arr[]={9,5,6,1,2,23,11,15,78,100,5};
    int arr_size = sizeof(arr)/sizeof(int);
    
    printf("Given array:\t");
    printArray(arr,arr_size);
     
    bubbleSort(arr,arr_size);

    printf("\nSorted array:\t");
    printArray(arr,arr_size);
    printf("\n");
    
}
