#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ANUBHAV JAIN
//22BIT0210

int stack[100];
int top = -1;

void push(int x) {
    if (top >= 100- 1) {
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

int evaluatePrefix(char* prefix) {
    int i, len = strlen(prefix);

    for (i = len - 1; i >= 0; i--) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            push(prefix[i] - '0');
        } else {
            int operand1 = pop();
            int operand2 = pop();
            int result;

            switch (prefix[i]) {
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
    char prefix[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}

