#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


int isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
        return 1;
    return 0;
}


int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}


void insert() {
    int value;
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}


void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {

        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
