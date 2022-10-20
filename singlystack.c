#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

// Push() 
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
    printf("\n\nNODE INSERTED\n\n");
}

int pop() {
    if (top == NULL) {
        printf("\n\nSTACK IS EMPTY\n\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    // Display 
    if (top == NULL) {
        printf("\nSTACK IS EMPTY\n");

    } else {
        printf("\n\nTHE STACK IS \n\n");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("\n%d--->NULL\n\n", temp->data);
    }
}

int main() {
    int choice, value;
    printf("\nImplementaion of Stack using Linked List\n");
    while (1) {
        printf("\n--------------------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
        if(top==NULL){
            printf("STACK IS EMPTY");
            break;
        }
        else
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}