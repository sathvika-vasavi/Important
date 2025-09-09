#include <stdio.h>
#define MAX 100   // maximum size of stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push an element into the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;  // return -1 if stack is empty
    }
    return s->arr[s->top--];
}

// Function to reverse an array using stack
void reverseArray(int arr[], int n) {
    struct Stack s;
    init(&s);

    // Push all elements into stack
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }

    // Pop all elements back into array
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

// Main function
int main() {
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, n);

    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
1st code
