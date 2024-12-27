/* Implementation of Doubly Linear Linked List*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev, *next;
    int data;
} Node;

Node *head = NULL;

Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insertAtBegin(int data)
{
    Node *new_node = createNode(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void insertAtEnd(int data)
{
    Node *new_node = createNode(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
    }
}

void insertAtPos(int data, int pos)
{
    Node *new_node = createNode(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *current = head;
        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;
    }
}

void forwardTraversal()
{
    printf("Forward Traversal: ");
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void backwardTraversal()
{
    printf("Backward Traversal: ");
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->prev;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\nLinkedList Operations:\n");
        printf("1. Insert at begin\t");
        printf("2. Insert at end\t");
        printf("3. Forward Travesal\t");
        printf("4. Backward Traversal\t");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtBegin(value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            forwardTraversal();
            break;
        case 4:
            backwardTraversal();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
