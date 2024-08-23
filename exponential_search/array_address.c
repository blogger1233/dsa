#include<stdio.h>
int main(){
	int arr[100];
	for(int i=0;i<100;i++){
		printf("Address of element arr[%d]: %p\n",i,&arr+i);
	}

	printf("\n%p\n",arr);
	return 0;
}
