#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ANIBHAV JAIN
//22BIT0210

struct Stack {
    int top;
    int capacity;
    char* array;
};

struct Stack* createStack( int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void infixToPrefix(char* infix, char* prefix)
{
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;
    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (isOperand(infix[i])) {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == ')') {
            push(stack, infix[i]);
        }
        else if (infix[i] == '(') {
            while (!isEmpty(stack) && peek(stack) != ')') {
                prefix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != ')') {
                printf("Invalid expression");
                return;
            }
            else {
                pop(stack);
            }
        }
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(peek(stack))) {
                prefix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main()
{
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    gets(infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s", prefix);
    return 0;
}
