class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
    myQueue() {
        // Initialize your data members
    }
    Node* front = NULL;
    Node* rear = NULL;
    int sizee = 0;
    bool isEmpty() {
        // check if the queue is empty
        return front == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* node = new Node(x);
        if(front == NULL && rear == NULL){
            front = node;
            rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
        sizee++;
    }

    void dequeue() {
        // Removes the front element of the queue
        Node* temp;
        temp = front;
        front = front->next;
        free(temp);
        sizee--;
        if(sizee == 0){
            front = NULL;
            rear = NULL;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty())
            return -1;
        return front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sizee;
    }
};
