#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#define NUM_RANKS 13
#define NUM_SUITS 4
int main(){
	bool seen[NUM_SUITS][NUM_RANKS]={false};
	const char ranks[NUM_RANKS]={'2','3','4','5','6','7','8','9','t','j','q','k','a'};
	const char suits[NUM_SUITS]={'s','c','d','h'};
	int num_cards,suit,rank;
	srand((unsigned)time(NULL));
	printf("Enter number of cards:");
	scanf("%d",&num_cards);
	printf("in hand:");
	while(num_cards>0){
	    int suit=rand()%NUM_SUITS;
	    int rank=rand()%NUM_RANKS;
	    if(!seen[suit][rank]){
		num_cards--;
		printf(" %c%c",ranks[rank],suits[suit]);
	    }
	}
	printf("\n");
	return 0;
}
