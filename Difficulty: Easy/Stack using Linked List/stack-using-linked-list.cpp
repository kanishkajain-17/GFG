/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
    myStack() {
        // Initialize your data members
    }
    Node * top = NULL;
    int sizee = 0;
    bool isEmpty() {
        // check if the stack is empty
        return top == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* node = new Node(x);
        node->next = top;
        top = node;
        sizee++;
    }

    void pop() {
        // Removes the top element of the stack
        Node * temp = top;
        top = top->next;
        free(temp);
        sizee--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty())
            return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sizee;
    }
};