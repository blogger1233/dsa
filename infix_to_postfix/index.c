#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char arr[100];
    int top;
} Stack;

int isFull(Stack *s) {
    return s->top == 99;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char e) {
    if (!isFull(s)) {
        s->arr[++s->top] = e;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    } else {
        printf("Stack underflow\n");
        return '\0';  // Return a null character on underflow
    }
}

int isOperand(char c) {
    return !(c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(' || c == ')');
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

char *infix_to_postfix(char *s, Stack *stack) {
    static char str1[100];
    int i = 0, j = 0;

    while (s[i] != '\0') {
        if (isOperand(s[i])) {
            str1[j++] = s[i++];
        } else {
            if (s[i] == '(') {
                push(stack, s[i++]);
            } else if (s[i] == ')') {
                while (!isEmpty(stack) && stack->arr[stack->top] != '(') {
                    str1[j++] = pop(stack);
                }
                pop(stack);  // Remove '('
                i++;
            } else {
                while (!isEmpty(stack) &&
                       (prec(s[i]) < prec(stack->arr[stack->top]) ||
                        (prec(s[i]) == prec(stack->arr[stack->top]) && s[i] != '^'))) {
                    str1[j++] = pop(stack);
                }
                push(stack, s[i++]);
            }
        }
    }

    while (!isEmpty(stack)) {
        str1[j++] = pop(stack);
    }

    str1[j] = '\0';
    return str1;
}

int main() {
    char str[100];
    printf("Enter infix: ");
    scanf("%s", str);

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;

    printf("Entered infix is %s\n", str);

    printf("Postfix: %s\n", infix_to_postfix(str, stack));

    free(stack);
    return 0;
}


