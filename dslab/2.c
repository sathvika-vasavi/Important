#include <stdio.h>
#include <string.h>
#define MAX 100   // maximum size of stack

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push character into stack
void push(struct Stack* s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = c;
}

// Pop character from stack
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        return '\0';  // return null char if empty
    }
    return s->arr[s->top--];
}

// Function to check matching brackets
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check balanced parentheses
int isBalanced(char* expr) {
    struct Stack s;
    init(&s);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push into stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // If closing bracket, check with stack top
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return 0; // no matching opening
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, ch)) {
                return 0; // mismatch
            }
        }
    }

    // At end, stack must be empty for balanced expression
    return isEmpty(&s);
}

// Main function
int main() {
    char expr[MAX];

    printf("Enter a mathematical expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("The expression is Balanced.\n");
    } else {
        printf("The expression is NOT Balanced.\n");
    }

    return 0;
}
