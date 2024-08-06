#include<stdio.h>
int binary_search(int *arr,int high,int low,int key){
	int mid = low+(high-low)/2;
	while(low<=high){
		if(arr[mid]==key){
			return mid;
		}else if(arr[mid]>key){
			return binary_search(arr,mid-1,low,key);
		}else{
			return binary_search(arr,high,mid+1,key);
		}
	}
	return -1;
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index=binary_search(arr,sizeof(arr)/sizeof(int)-1,0,56);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}
	else{
		printf("Element not found\n");
	}
	
}
