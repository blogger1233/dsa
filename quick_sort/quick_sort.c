#include<stdio.h>
#define SIZE 6
int swap(int *a,int *b){
    int t = *a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high){
    int i= low-1;
    int pivot = arr[high];
    for(int j=low;j<high;j++){
	if(arr[j]<pivot){
	    i++;
	    if(i<j){
		swap(&arr[i],&arr[j]);//passing address
	    }
	}	
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    
    if(low<high){
	int position = partition(arr,low,high);

	quickSort(arr,low,position-1);
	quickSort(arr,position+1,high);
    }

}
int main(){
	int arr[]={5,1,3,4,2,6};
	quickSort(arr,0,SIZE-1);
	//sorted array
	printf("Sorted array:");
	for(int i=0;i<SIZE;i++){
		printf(" %d",arr[i]);
	}
	printf("\n");
	return 0;
}
