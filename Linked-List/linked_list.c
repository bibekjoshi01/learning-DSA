/* Implementation of Linear Singly Linked List*/

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
    return node;
}

Node *insertAtBegining(Node *head, int data)
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

void displayList(Node *head)
{
    printf("List Elements: ");
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }

    printf("\n");
    return;
}

void searchList(Node *head, int target)
{
    while (head != NULL)
    {
        if (head->data == target)
        {
            printf("Target found !\n");
            return;
        }
        head = head->next;
    }

    printf("Target not found!\n");
    return;
}

void deleteLastNode(Node *head)
{
    if(head == NULL){
        printf("Empty List!");
        return;
    }

    if (head->next == NULL){
        printf("Deleted element is: %d", head->data);
        free(head);
        return;
    }

    Node *prev = head;
    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
    }

    printf("Deleted element is: %d\n", head->data);
    prev->next = NULL;

    free(head);
}

int main()
{
    Node *head = createNode(5);

    head = insertAtBegining(head, 10);
    head = insertAtBegining(head, 15);
    head = insertAtEnd(head, 17);
    displayList(head);
    searchList(head, 16);
    searchList(head, 10);
    deleteLastNode(head);
    head = insertAtEnd(head, 34);
    displayList(head);

    return 0;
}
