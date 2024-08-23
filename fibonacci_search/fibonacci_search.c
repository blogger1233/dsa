#include<stdio.h>
int min(int a,int b){
	return a<b?a:b;
}
int fibonacci_search(int *arr,int size,int key){
	int fibm2=0;
	int fibm1=1;
	int fibm=fibm1+fibm2;
	while(fibm<size){
		fibm2=fibm1;
		fibm1=fibm;
		fibm=fibm1+fibm2;	
	}
	int offset=-1;
	while(fibm>1){
		int i= min(offset+fibm2,size-1);
		if(arr[i]<key){
			fibm=fibm1;
			fibm1=fibm2;
			fibm2=fibm-fibm1;
			offset=i;
		}
		else if(arr[i]>key){
			fibm=fibm2;
			fibm1=fibm1-fibm;
			fibm2=fibm-fibm1;
		}
		else{
			return i;	
		}
	}
	if(fibm&&arr[offset+1]==key){
		return offset+1;
	}
	return -1;
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index = fibonacci_search(arr,sizeof(arr)/sizeof(int),56);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}
	else{
		printf("Element not found\n");
	}
	return 0;
}
