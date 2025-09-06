#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct node {
    int data;
    struct node *next;
} node;

node *Hashtable[size];

int hashfunction(int key) {
    return key % size;
}

void insert(int key) {
    int index = hashfunction(key);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = key;
    newnode->next = NULL;

    if (Hashtable[index] == NULL) {
        Hashtable[index] = newnode;
    } else {
        newnode->next = Hashtable[index];
        Hashtable[index] = newnode;
    }
    printf("Element %d Inserted!\n\n", key);
}

void search(int key) {
    int index = hashfunction(key);
    node *temp = Hashtable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at index %d\n\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n\n", key);
}

void Display() {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        node *temp = Hashtable[i];

        if (temp == NULL) {
            printf("NULL");
        } else {
            while (temp != NULL) {
                printf("%d->", temp->data);
                temp = temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

void delete(int key) {
    int index = hashfunction(key);
    node *temp = Hashtable[index];
    node *prev = NULL;

    if (temp == NULL) {
        printf("Element %d not found\n", key);
        return;
    }

    if (temp->data == key) {
        Hashtable[index] = temp->next;
        free(temp);
        printf("Element %d deleted successfully\n", key);
        return;
    }

    while (temp != NULL) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            printf("Element %d deleted successfully\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Element %d not found\n", key);
}

int main() {
    int choice, key;

    for (int i = 0; i < size; i++) {
        Hashtable[i] = NULL;
    }

    do {
        printf("---HashTable Menu---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exist\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter the element to be deleted: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("Exiting the program!!\n");
                break;
            default:
                printf("Please enter a valid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
