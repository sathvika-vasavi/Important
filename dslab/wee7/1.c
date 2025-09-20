#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <stdlib.h>  // for atoi()

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        char c = exp[i];

        // If character is a digit, push to stack
        if (isdigit(c)) {
            push(c - '0');   // convert char to int
        }
        // If operator, pop two elements and apply operation
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop(); // Final result
}

// Main function
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (single-digit operands, no spaces): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
