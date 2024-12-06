/* Implementing Queue using Array in C */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear, capacity;
    int *queue;
} Queue;

// Function to initialize the queue
Queue *createQueue(int capacity)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->queue = (int *)malloc(q->capacity * sizeof(int));
    return q;
}

void enque(Queue *queue, int item)
{
    if (queue->rear >= queue->capacity)
    {
        printf("Queue is full !");
        return;
    }
    else
    {
        queue->queue[++queue->rear] = item;
    }
}

int deque(Queue *queue)
{
    if (queue->rear < queue->front)
    {
        printf("Queue is empty.");
        return -1;
    }
    else
    {
        return queue->queue[queue->front++];
    }
}

void displayQueue(Queue *queue)
{
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d\t", queue->queue[i]);
    }
}

int main()
{
    struct Queue *q1 = createQueue(4);
    displayQueue(q1);
    enque(q1, 5);
    enque(q1, 1);
    printf("Deque: %d\n", deque(q1));
    printf("Deque: %d\n", deque(q1));
    printf("Deque: %d\n", deque(q1));
    printf("Deque: %d\n", deque(q1));
    enque(q1, 2);
    displayQueue(q1);

    return 0;
}