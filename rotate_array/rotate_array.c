#include<stdio.h>
#define N 10
int main(){
	int arr[N];
	for(int i=0;i<N;i++){
	    arr[i]=i+1;
	}
	printf("Enter no of times to rotate an array:");
	int k;
	scanf("%d",&k);
	int temp[N];
	if(k==0){
	    for(int i=0;i<N;i++){
		printf(" %d",arr[i]);
	    }
	}else{
	    for(int i=0;i<N;i++){
		temp[((k+i)%N)]=arr[i];
	    }
	    for(int i=0;i<N;i++){
		printf(" %d",temp[i]);
	    }

	}
	printf("\n");
	return 0;
}
