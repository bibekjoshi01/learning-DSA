// C Program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5

typedef struct Stack
{
    int items[SIZE];
    int top;
} Stack;

// Function to Create stack
void createStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s)
{
    return s->top == SIZE - 1;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot peek.\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    else
    {
        return s->items[(s->top)--];
    }
}

int push(Stack *s, int element)
{
    if (isFull(s))
    {
        printf("Stack overflow! Cannot push %d\n", element);
        return -1;
    }
    else
    {
        s->items[++(s->top)] = element;
        printf("Pushed %d onto the stack. \n", element);
    }
}

int main()
{
    Stack stack;

    createStack(&stack);

    push(&stack, 10);
    push(&stack, 30);
    push(&stack, 60);
    printf("Top element is: %d\n", peek(&stack));
    printf("Popped element is: %d\n", pop(&stack));
    push(&stack, 10);
    push(&stack, 30);
    push(&stack, 60);
    push(&stack, 100); // Should raise overflow

    return 0;
}