#include<stdio.h>
#include<stdlib.h>
#define DIGIT 10
int main(){
	int seen[DIGIT]={0};
	long number;
	printf("Enter number:");
	scanf("%ld",&number);
	while(number>0){
	    long digit = number%10;
	    if(!seen[digit]){
		seen[digit]=1;	
	    }else{
		seen[digit]+=1;
	    }
	    number=number/10;
	}
	printf("Digit:\t\t");
	for(int i=0;i<DIGIT;i++){
	    printf("%d ",i);
	}
	printf("\n");
	printf("Occurrence:\t");
	for(int i=0;i<DIGIT;i++){
	    printf("%d ",seen[i]);
	}
	printf("\n");
	return 0;
}

