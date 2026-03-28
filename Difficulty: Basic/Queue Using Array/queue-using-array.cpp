class myQueue {
    private:
    vector<int>nums;
    int rear;
    int front;
    int capacity;

  public:
    myQueue(int n) {
        // Define Data Structures
        nums.resize(n);
        rear = -1;
        front = -1;
        capacity = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (front == -1 || front > rear);
    }

    bool isFull() {
        // check if the queue is full
        return rear == capacity - 1 && front == 0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())
            return;
            
        if(rear == -1 && front == -1 || front > rear){
            rear = 0;
            front = 0;
            nums[rear] = x;
        }
        else{
            rear++;
            nums[rear] = x;
        }
        
        
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
            return;
        int x = nums[front];
        front++;
        
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
            return -1;
        return nums[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())
            return -1;
        return nums[rear];
    }
};