#include<stdio.h>
#include<string.h>
//ANUBHAV JAIN
//22BIT0210
struct Stack {
    char data[70][70];
    int top;
} st;

void Push(char ele[]) {
    if (st.top + 1 > 70) {
        printf("\nStack Overflow\n");
    } else {
        st.top++;
        strcpy(st.data[st.top], ele);
    }
}

void Pop() {
    if (st.top == -1) {
        printf("Stack Underflow");
    } else {
        printf("Deleted Register No. = %s\n", st.data[st.top]);
        st.top--;
    }
}

void Disp() {
    int i;
    for (i = st.top; i >= 0; i--) {
        printf("\n%s", st.data[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j;
    char val[70];
    st.top = -1;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Now, enter the reg. nos\n");
    for (i = 0; i < n; i++) {
        int f = 1;
        scanf("%s", val);
        if (st.top != -1) {
            int t = st.top;
            for (j = 0; j <= t; j++) {
                if (strcmp(val, st.data[j]) == 0) {
                    f = 0;
                    printf("\nNumber already Exists\n");
                    i--;
                    break;
                }
            }
            if (f == 0) continue;
            Push(val);
        } else {
            Push(val);
        }
    }
    int m = 10;
    int t = st.top;
    for (i = st.top; i >= m; i--) {
        Pop();
    }
    printf("\nNow Printing the first %d Numbers:\n", m);
    Disp();
    return 0;
}
