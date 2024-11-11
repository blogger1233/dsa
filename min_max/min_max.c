#include<stdio.h>

void min_max(int arr[],int N,int *min,int *max){
    *min=*max=arr[0];
    for(int i=1;i<N;i++){
	if(arr[i]>*max){
	    *max = arr[i];
	}else if(arr[i]<*min){
	    *min= arr[i];
	}
    }
}
int main(){
    int arr[10],min,max;
    printf("Enter array: ");
    for(int i = 0;i<10;i++){
	scanf("%d",&arr[i]);
    }
    min_max(arr,10,&min,&max);
    printf("Largest Element: %d\n",max);
    printf("Smallest Element: %d\n",min);
    return 0;

}
