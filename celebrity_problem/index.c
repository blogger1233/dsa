#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 4
typedef struct Stack{
    int data[MAX_SIZE]; //Array to hold stack elements
    int top; //Index of top element
} Stack;

void initalize(Stack *s){
    s->top = -1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
int isFull(Stack *s){
    return s->top==MAX_SIZE-1;
    
}
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->top++;              
        s->data[s->top] = value; 
        printf("Pushed successfully\n");
    } else {
        printf("Unable to push element\n");
        printf("Stack overflow!!!\n");
    }
}
int pop(Stack *s){
    if(!isEmpty(s)){
	int i = s->top;
	s->top--;
	printf("Popped successfully\n");
	return s->data[i];
    }else{
	printf("Unable to pop element\n");
	printf("Stack is empty\n");
	return -1;
    }

}

void printStack(Stack *s){
    int i=s->top;
    printf("x---x\n");
    while(i>-1){
	printf("| %d |\n",s->data[i]);
	i--;
    }
    printf("x---x\n");
    printf("x----------x\n");
}
void celebrity(int arr[][4],Stack * s)
{
	int i =0;
	int guests = sizeof(arr[i])/sizeof(int);
	for(int j=0;j<guests;j++){
	    push(s,j);
	}
	while(s->top>0){
	    int  i = pop(s);
	    int j = pop(s);
	    if(arr[i][j]==1){
		push(s,j);
	    }
	    else{
		push(s,i);
	    }
	}
	 i = pop(s);
	for(int q =0;q<guests;q++){
	    if(arr[i][q]==1){
		printf("There is no celebrity in the party\n");
		break;
	    }
	    

	}
	printf("Guest %d is celebrity\n",i);
    
}
int main(){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	initalize(s);
	int arr[4][4] = {
    {0, 1, 1, 1}, // Guest 0 knows guests 1, 2, and 3
    {0, 0, 1, 1}, // Guest 1 knows guests 2 and 3
    {0, 0, 0, 1}, // Guest 2 knows guest 3
    {0, 0, 0, 0}  // Guest 3 knows nobody (potential celebrity)
};

	celebrity(arr,s);
	free(s);
	return 0; 
}
