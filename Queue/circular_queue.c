#include <stdio.h>
#include <stdlib.h>

// Circular Queue structure
typedef struct {
    int *items;
    int front, rear;
    int capacity;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue *q, int capacity) {
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->items = (int *)malloc(capacity * sizeof(int));
    if (q->items == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Check if the circular queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

// Check if the circular queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Circular queue is full! Cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->capacity;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Dequeue operation
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", q->items[q->front]);
        if (q->front == q->rear) { // Only one element was in the queue
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->capacity;
        }
    }
}

// Peek operation
void peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty! No front element.\n");
    } else {
        printf("Front element: %d\n", q->items[q->front]);
    }
}

// Display the circular queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty!\n");
    } else {
        printf("Circular queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % q->capacity;
        }
        printf("\n");
    }
}

// Free dynamically allocated memory
void freeQueue(CircularQueue *q) {
    free(q->items);
}

int main() {
    CircularQueue q;
    int choice, value, capacity;

    printf("Enter the capacity of the circular queue: ");
    scanf("%d", &capacity);

    initializeQueue(&q, capacity);

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Peek\t");
        printf("4. Display\t");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting...\n");
                freeQueue(&q);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
