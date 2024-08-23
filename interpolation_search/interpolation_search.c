#include<stdio.h>
int interpolation_search(int *arr,int high,int low,int key){
	int probe;
	while(low<=high&&key>=arr[low]&&key<=arr[high]){
		probe = low+ (((key-arr[low])*(high-low))/(arr[high]-arr[low]));
		if(key==arr[probe]){
			return probe;
		}
		if(arr[probe]>key){
			return interpolation_search(arr,probe-1,low,key);
		}
		if(arr[probe]<key){
			return interpolation_search(arr,high,probe+1,key);
		}
	}
	return -1;

}

int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		arr[i]=i+1;
	}
	int index = interpolation_search(arr,sizeof(arr)/sizeof(int)-1,0,76);
	if(index!=-1){
		printf("Element found at index: %d\n",index);
	}else{
		printf("Element not found\n");
	}
	return 0;

}
