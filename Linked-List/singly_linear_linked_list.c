// Implementation of Singly Linear Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void searchList(Node *head, int target)
{
    while (head != NULL)
    {
        if (head->data == target)
        {
            printf("Target found!\n");
            return;
        }
        head = head->next;
    }

    printf("Target not found!\n");
    return;
}

int lengthList(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

Node *insertAtBegin(Node *head, int data)
{
    Node *new_node = createNode(data);
    new_node->next = head;
    return new_node;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *new_node = createNode(data);

    if (head == NULL)
    {
        return new_node;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

Node *insertAtPosition(Node *head, int pos, int data)
{
    if (pos < 1)
    {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1)
    {
        struct Node *new_node = createNode(data);
        new_node->next = head;
        return new_node;
    }

    Node *prev = head;
    int count = 1;
    while (count < pos && prev != NULL)
    {
        prev = prev->next;
        count++;
    }

    if (prev == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }

    Node *new_node = createNode(data);
    new_node->next = prev->next;
    prev->next = new_node;
}

int main()
{
    Node *head = createNode(5);
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 8);
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 4);
    displayList(head);
    searchList(head, 5);
    searchList(head, 4);
    printf("Length of Linked List is %d\n", lengthList(head));

    return 0;
}