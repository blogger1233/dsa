#include<stdio.h>
#include<stdlib.h>


#define MAX 5

int stack[MAX];
int top = -1;

int isFull(){
    return top ==MAX-1;
}
int isEmpty(){
    return top == -1;
}
void push(int element){
    if(isfull()){
	printf("Stack Overflow! unable to push %d\n",element);
    }
    else{
	stack[++top]= value;
	printf("%d pushed to the stack\n",value);
    }

}
int pop(){
    if(isEmpty()){
	printf("Stack underflow! unable to pop\n");
	return -1;
    }
    else{
	printf("%d popped from the stack\n",stack[top]);
	return stack[top--];
    }
}
int peek(){
    if(isEmpty()){
	printf("Stack is empty! Unable to peek!!\n");
	return -1;
    }
    else{
	return stack[top];
    }
}

