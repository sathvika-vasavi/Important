#include <stdio.h>
#include <string.h>
#include <ctype.h>   // for isalnum()

#define MAX 100

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
        return '\0';
    }
    return s->arr[s->top--];
}

// Peek top element of stack
char peek(struct Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    init(&s);
    int k = 0; // index for postfix expression

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // pop '('
        }
        // If operator
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // null terminate string
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);   // Reads without spaces

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
