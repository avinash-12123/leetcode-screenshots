#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

struct node *insert_end(int data)
{
    struct node *newnode = create(data);

    if (head == NULL)
    {
        return newnode;
    }

    struct node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newnode;
    newnode->prev = current;

    return head;
}

void insert_left(int new_data, int key_value)
{
    struct node *newnode = create(new_data);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *current = head;

    while (current != NULL && current->data != key_value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Target node with value %d not found. node not inserted.\n", key_value);
        free(newnode);
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;

    if (current->prev != NULL)
    {
        current->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }

    current->prev = newnode;
}

void search(int key)
{
    struct node *current = head;
    int pos = 0;

    while (current != NULL && current->data != key)
    {
        pos++;
        current = current->next;
    }

    if (current == NULL || current->data != key)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d\n", pos + 1);
    }
}
void delete_spec(int key)
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Element deleted successfully.\n");
}


void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;
    printf("Doubly Linked List is: ");

    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void main()
{
    int ch, value, key;

    do
    {
        printf("\n1.insert end");
        printf("\n2.insert left");
        printf("\n3.delete spec. value");
        printf("\n4.search");
        printf("\n5.display");
        printf("\n6.exit\n");

        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
               printf("enter the value to be inserted: ");
               scanf("%d", &value);
               head = insert_end(value);
               break;

            case 2:
                printf("enter the new value and key value: ");
                scanf("%d %d", &value, &key);
                insert_left(value, key);
                break;

            case 3:
                printf("enter the value of a node to be deleted: ");
                scanf("%d", &key);
                delete_spec(key);
                break;

            case 4:
                printf("enter the value to be searched: ");
                scanf("%d", &key);
                search(key);
                break;

            case 5:
                display();
                break;

            case 6:
                break;

            default:
                printf("your choice is wrong!..\n");
        }

    } while (ch != 6);
}
