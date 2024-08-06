#include<stdio.h>

int ternary_search(int *arr,int high,int low,int key){
	int mid1= low+(high-low)/3;
	int mid2= high-(high-low)/3;
	while(low<=high){
		if(arr[mid1]==key){
			return mid1;
		}
		if(arr[mid2]==key){
			return mid2;
		}

		if(key<arr[mid1]){
			return ternary_search(arr,mid1-1,low,key);
		}
		else if(key>arr[mid2]){
			return ternary_search(arr,high,mid2+1,key);
		}else{
			return ternary_search(arr,mid2-1,mid1+1,key);
		}
	}
	return -1;
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index = ternary_search(arr,sizeof(arr)/sizeof(int)-1,0,77);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}else{
		printf("Element not found\n");
	}
	return 0;

}
