#include <stdio.h>
#include <stdlib.h>

typedef struct LinearQueue
{
    int front, rear, capacity, *array;
} LinearQueue;

LinearQueue *initializeLinearQueue(int capacity)
{
    LinearQueue *q = (LinearQueue *)malloc(sizeof(LinearQueue));
    q->capacity = capacity;
    q->rear = -1;
    q->front = 0;
    q->array = (int *)malloc(capacity * sizeof(int));
    return q;
}

void enqueue(LinearQueue *queue, int item)
{
    if (queue->rear >= queue->capacity - 1)
    {
        printf("\nQueue is full!");
        exit(0);
    }
    else
    {
        queue->array[++queue->rear] = item;
    }
}

int dequeue(LinearQueue *queue)
{
    if (queue->front > queue->rear)
    {
        printf("\nQueue is empty");
        exit(0);
    }
    else
    {
        return queue->array[queue->front++];
    }
}

void displayQueue(LinearQueue *queue)
{
    for (int index = queue->front; index <= queue->rear; index++)
    {
        printf("%d\t", queue->array[index]);
    }
}

int main()
{
    LinearQueue *queue = initializeLinearQueue(5);
    enqueue(queue, 3);
    enqueue(queue, 7);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 7);
    displayQueue(queue);
    printf("\n%d removed from queue.\n", dequeue(queue));
    displayQueue(queue);
    enqueue(queue, 9); 
    return 0;
}