#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <string.h>  // for strlen()

#define MAX 100

int stack[MAX];
int top = -1;

// Push to stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Pop from stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Evaluate prefix expression
int evaluatePrefix(char exp[]) {
    int i, len = strlen(exp);

    // Scan from right to left
    for (i = len - 1; i >= 0; i--) {
        char c = exp[i];

        // If operand, push to stack
        if (isdigit(c)) {
            push(c - '0');  // convert char to int
        }
        // If operator, pop two elements and apply operation
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int val1 = pop();
            int val2 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop(); // final result
}

// Main function
int main() {
    char prefix[MAX];

    printf("Enter prefix expression (single-digit operands, no spaces): ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result of prefix evaluation: %d\n", result);

    return 0;
}
