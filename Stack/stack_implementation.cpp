#include <iostream>

#define SIZE 100

using namespace std;

class Stack
{
    int top;

public:
    int stack[SIZE];

    Stack()
    {
        top = -1;
    }
    bool push(int element);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int element)
{
    if (top >= SIZE - 1)
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        stack[++top] = element;
        cout << element << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow";
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack underflow";
        return 0;
    }
    else
    {
        return stack[top];
    }
}

bool Stack::isEmpty()
{
    return top < 0;
}

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(60);

    cout << s.pop() << " popped from stack \n";
    cout << s.peek() << " is top element from stack \n";

    // Elements in the stack
    cout << "Elements inside stack" << endl;
    while (!s.isEmpty())
    {
        cout << s.pop() << endl;
    }

    return 0;
}