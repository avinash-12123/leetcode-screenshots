#include <stdio.h>
#include <stdlib.h> 

#define SIZE 10

void push(int value);
void pop();
void display();
void peek();

int stack[SIZE], top = -1;

int main()
{
    int value, choice;

    while (1)
    {
        printf("\n\n***** MENU *****");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong selection!!! Try again!!!\n");
        }
    }

    return 0;
}

void push(int value)
{
    if (top == SIZE - 1)
        printf("Stack is full!!! Insertion is not possible!!!\n");
    else
    {
        stack[++top] = value;
        printf("Insertion success!!!\n");
    }
}

void pop()
{
    if (top == -1)
        printf("Stack is empty!!! Deletion is not possible!!!\n");
    else
    {
        printf("Deleted: %d\n", stack[top--]);
    }
}

void display()
{
    if (top == -1)
        printf("Stack is empty!!!\n");
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void peek()
{
    if (top != -1)
        printf("Top element (peek): %d\n", stack[top]);
    else
        printf("Stack is empty. Nothing to peek!\n");
}

