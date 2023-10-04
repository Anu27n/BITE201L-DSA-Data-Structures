#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ANUBHAV JAIN
//22BIT0210
char stack[100];
int top = -1;

void push(int x) {
    if (top >= 100 - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
