#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *head = NULL;


int count() {
    struct node *temp = head;
    int i = 0;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}


struct node *create(int value) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}


void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}

void delete_begin() {
    struct node *temp;
    if (head == NULL) {
        printf("Deletion is not possible\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted %d from beginning\n", temp->data);
        free(temp);
    }
}


void delete_end() {
    struct node *temp1, *temp2;
    if (head == NULL) {
        printf("Deletion is not possible\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp1 = head;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    printf("Deleted %d from end\n", temp1->data);
    free(temp1);
}


void delete_pos(int pos) {
    struct node *temp1, *temp2;
    int c = 1, n;
    n = count();
    if (pos < 1 || pos > n) {
        printf("Deletion is not possible\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }
    temp1 = head;
    while (c < pos && temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        c++;
    }
    temp2->next = temp1->next;
    printf("Deleted %d from position %d\n", temp1->data, pos);
    free(temp1);
}


void delete_spec_value(int key) {
    struct node *temp1 = head, *temp2 = NULL;
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (temp1->data == key) {
        head = temp1->next;
        printf("Element %d deleted\n", key);
        free(temp1);
        return;
    }

    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }


    temp2->next = temp1->next;
    printf("Element %d deleted\n", key);
    free(temp1);
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL)
                printf("-> ");
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, pos, value, key;

    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Delete at beginning\n");
        printf("3. Delete at end\n");
        printf("4. Delete at position\n");
        printf("5. Delete by key\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                delete_begin();
                break;

            case 3:
                delete_end();
                break;

            case 4:
                printf("Enter position you want to delete: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 5:
                printf("Enter key value of a node you want to delete: ");
                scanf("%d", &key);
                delete_spec_value(key);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Your choice is wrong! Try again.\n");
        }
    } while (ch != 7);

    return 0;
}
