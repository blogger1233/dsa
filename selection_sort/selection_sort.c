#include<stdio.h>

void selectionSort(int arr[],int size){
	
    for(int i=0;i<size;i++){
	int index = i;
	
	for(int j=i+1;j<size;j++){
	    if(arr[index]>arr[j]){

		index=j;
	    }

	}
	int t = arr[i];
	arr[i]=arr[index];
	arr[index]=t;
    }

}


int main(){
	int arr[]={11,45,89,45,2,10,5,7};
	selectionSort(arr,sizeof(arr)/sizeof(int));
	for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
	    printf(" %d",arr[i]);
	}
	printf("\n");
	return 0;
}
