#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX];
int front = -1;
int rear = -1;


void insert() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}


void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Queue Operations Menu ***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
