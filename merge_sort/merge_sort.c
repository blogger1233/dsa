#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1= mid+1-low;
    int n2= high-mid;

    int L[n1],R[n2];
    for(int i = 0;i<n1;i++){
	L[i]=arr[low+i];
    }
    for(int j = 0;j<n2;j++){
	R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1&&j<n2){
	if(L[i]<=R[j]){
	    arr[k]=L[i];
	    i++;
	}else{
	    arr[k]=R[j];
	    j++;
	}
	k++;
    }
    while(i<n1){
	arr[k]=L[i];
	i++;
	k++;
    }
    while(j<n2){
	arr[k]=R[j];
	j++;
	k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
	int mid = low+(high-low)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
    }
}

int main(){
	int arr[]={1,78,0,12,56,2,3,5};
	int arr_size = sizeof(arr)/sizeof(int);
	printf("Given array:\t");
	for(int i = 0;i<arr_size;i++){
	    printf(" %d",arr[i]);
	}
	mergeSort(arr,0,arr_size-1);
	printf("\nSorted array:\t");
	for(int i =0;i<arr_size;i++){
	    printf(" %d",arr[i]);
	}
	printf("\n");
	return 0;
}
