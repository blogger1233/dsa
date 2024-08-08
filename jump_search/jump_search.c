#include<stdio.h>
#include<math.h>
int min(int a, int b){
	return a<b?a:b;
}
int jump_search(int *arr,int size,int key){
	
	int step= sqrt(size);
	int prev = 0;
	

	while(arr[min(step,size)-1]<key){
		prev=step;
		step+=sqrt(size);
		if(prev>=size){
			return -1;
		}
	}		
	while(arr[prev]<key){
		prev++;
		if(prev==min(size,step)){
			return -1;
		}
	}
	if(arr[prev]==key){
		return prev;
	}
	return -1;
	
}

int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index = jump_search(arr,sizeof(arr)/sizeof(int),56);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}else{
		printf("Element not found\n");
	}
	return 0;

}
