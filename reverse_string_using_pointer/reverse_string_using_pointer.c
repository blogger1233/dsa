#include<stdio.h>
#define N 10

int main(){
    int arr[N],*ptr;

    printf("Enter array:");
    for(ptr=arr;ptr<arr+N;ptr++){
	scanf("%d",ptr);
    }
    printf("reversed array:");
    for(ptr=arr+N-1;ptr>=arr;--ptr){
	printf(" %d",*ptr);
    }
    printf("\n");
    return 0;
}
