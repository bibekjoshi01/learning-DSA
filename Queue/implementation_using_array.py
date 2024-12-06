class Queue:
    def __init__(self, capacity):
        self.front = 0
        self.rear = -1
        self.capacity = capacity
        self.queue = [None] * capacity
    
    def is_full(self) -> bool:
        return (self.rear >= self.capacity - 1)
    
    def is_empty(self) -> bool:
        return (self.rear < self.front)
    
    def enque(self, item):
        if self.is_full():
            print("Queue is full")
            return
        else:
            self.rear = self.rear + 1
            self.queue[self.rear] = item
    
    def deque(self):
        if self.is_empty():
            print("Queue is empty")
            return
        else:
            item = self.queue[self.front]
            self.front = self.front + 1
            return item

        
if __name__ == "__main__":
    queue = Queue(4)
    print(queue.queue)

    queue.enque(5)
    queue.enque(1)
    queue.enque(6)
    queue.enque(4)
    queue.enque(4)

    print(queue.queue)
    
    print(queue.deque())
    print(queue.deque())
    print(queue.deque())
    print(queue.deque())
    print(queue.deque())
