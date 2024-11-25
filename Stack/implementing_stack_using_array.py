class Stack:
    def __init__(self):
        self.stack = []

    # Stack is empty when stack size is 0
    def is_empty(self):
        return len(self.stack) == 0

    # Function to add an item to stack. It increases size by 1
    def push(self, item):
        self.stack.append(item)
        print(str(item) + " pushed to stack.")

    # Function to remove an item from stack. It decreases size by 1
    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        return self.stack.pop()

    # Function to return the top from stack without removing it
    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        return self.stack[-1]


if __name__ == '__main__':
    stack = Stack()
    print(stack.pop())
    stack.push(30)
    stack.push(40)
    stack.push(20)
    print(stack.peek())
