#include<stdio.h>
int min(int a, int b){
	return a<b?a:b;
}
int binary_search(int *arr,int low,int high,int key){
	int mid = low+(high-low)/2;
	while(low<=high){
		if(arr[mid]==key){
			return key;
		}else if(arr[mid]>key){
			return binary_search(arr,low,mid-1,key);
		}else if(arr[mid]<key){
			return binary_search(arr,mid+1,high,key);
		}
	}
	return -1;
}
int exponential_search(int *arr,int size,int key){
	if(arr[0]==key){
		return 0;
	}
	int i=1;
	while(i<size-1&&arr[i]<=key){
		i=i*2;
	}
	return binary_search(arr,i/2,min(i,size-1),key);
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index= exponential_search(arr,100,67);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}else{
		printf("Element not found\n");
	}
}
