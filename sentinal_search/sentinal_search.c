#include<stdio.h>

int sentinal_search(int *arr,int size,int key)
{
	int last = arr[size-1];
	arr[size-1]=key;
	int i=0;
	while(arr[i]!=key){
		i++;
	}
	arr[size-1]=last;
	if((i<=size-1)||(arr[size-1]==key)){
		return i;
	}else{
		return -1;
	}
}
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index=sentinal_search(arr,sizeof(arr)/sizeof(int),78);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}else{
		printf("Element not found\n");
	}
	return 0;

}
