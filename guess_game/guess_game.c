#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_NUMBER 100
/*external variable*/
int secret_number;

void init(void);
void set_random_number(void);
void guess(void);

int main(){
	char command;
	printf("Guess the secret number between 1 and %d.\n",MAX_NUMBER);

	do{
	    init();
	    set_random_number();
	    printf("A new number has been chosen.\n");
	    guess();
	    printf("Play again? (Y/n)");
	    scanf(" %c",&command);

	}while(command == 'y' || command == 'Y');

	return 0;
}
void init(void){    
    srand((unsigned)time(NULL)); 
}
void set_random_number(void){
    secret_number = rand()%MAX_NUMBER+1; 
}
void guess(void){
    int guess, times = 0;
    for(;;){
	times++;
	printf("Enter guess: ");
	scanf("%d",&guess);
	if(guess == secret_number){
	    printf("You won in %d guesses!\n",times);
	    return;
	}else if(guess>secret_number){
	    printf("Too high! try again.\n");
	}else{
	    printf("Too low! try again.\n");
	}
    }

}
