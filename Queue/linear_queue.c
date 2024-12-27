/* Implementing Linear Queue using array */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear, capacity;
    int *array;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int *)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue *queue, int data)
{
    if (queue->rear == queue->capacity - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        queue->array[++queue->rear] = data;
        printf("Enqueued: %d\n", data);
    }
}

void dequeue(Queue *queue)
{
    if (queue->front > queue->rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("Dequeued: %d\n", queue->array[queue->front++]);
    }
}

void display(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->array[i]);
        }
        printf("\n");
    }
}

void peek(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty! No front element.\n");
    } else {
        printf("Front element: %d\n", q->array[q->front]);
    }
}


void freeQueue(Queue *q)
{
    free(q->array);
}

int main()
{
    int choice, value, capacity;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue *q = createQueue(capacity);


    do
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Peek\t");
        printf("4. Display\t");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            display(q);
            break;
        case 5:
            printf("Exiting...\n");
            freeQueue(q);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}