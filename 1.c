#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create circular linked list from array
void createCircularList(int arr[], int n) {
    struct Node *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head; // circular
}

// Display list
void displayCircularList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    struct Node* last = head;
    while (last->next != head) last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Delete after key
void deleteAfterKey(int key) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* delNode = temp->next;
            if (delNode == head) head = head->next;
            if (delNode == temp) {
                head = NULL; 
                free(delNode);
                return;
            }
            temp->next = delNode->next;
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Delete before key
void deleteBeforeKey(int key) {
    if (head == NULL || head->next == head) return;
    if (head->data == key) { 
        struct Node *temp = head, *prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
        return;
    }
    struct Node *prev = head, *curr = head->next;
    while (curr->next != head) {
        if (curr->next->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    int arr[] = {5, 10, 20, 25, 35, 40, 50};
    createCircularList(arr, 7);

    printf("Initial list: ");
    displayCircularList();

    deleteFromBeginning();
    printf("After deleting from beginning: ");
    displayCircularList();

    deleteFromEnd();
    printf("After deleting from end: ");
    displayCircularList();

    deleteAfterKey(25);
    printf("After deleting node after 25: ");
    displayCircularList();

    deleteBeforeKey(35);
    printf("After deleting node before 35: ");
    displayCircularList();

    return 0;
}
