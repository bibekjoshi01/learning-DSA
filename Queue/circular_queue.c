#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int front, rear, capacity, *array;
} CircularQueue;

CircularQueue *initializeCircularQueue(int capacity)
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

void enqueue(CircularQueue *queue, int item)
{
    // Check if queue if full
    if (queue->front == (queue->rear + 1) % queue->capacity)
    {
        printf("Queue is full!");
        exit(0);
    }
    else
    {
        queue->array[queue->rear] = item;
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
}

int dequeue(CircularQueue *queue)
{
    // Check if queue if empty
    if (queue->front == queue->rear)
    {
        printf("Queue if empty!");
        exit(0);
    }
    else
    {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        return item;
    }
}

void displayQueue(CircularQueue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int index = queue->front;
    while (index != queue->rear)
    {
        printf("%d\t", queue->array[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

int main()
{
    CircularQueue *queue = initializeCircularQueue(5);
    displayQueue(queue);
    enqueue(queue, 0);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 4);
    enqueue(queue, 0);
    // enqueue(queue, 4);
    displayQueue(queue);

    return 0;
}