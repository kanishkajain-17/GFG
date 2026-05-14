class minHeap {
  private:
    // Initialize your data members
    vector<int> heap;
  public:

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        int n = heap.size() - 1;
        
        while (n > 0) {
            int parent = (n - 1) / 2;
            if(heap[parent] > heap[n]) {
                swap(heap[parent], heap[n]);
                n = parent;
            }
            else
                break;
        }
    }

    void pop() {
        // Remove the top (minimum) element
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0;
        
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            int smallest = i;
            
            if(left < heap.size() && heap[left] < heap[smallest])
                smallest = left;
            if(right < heap.size() && heap[right] < heap[smallest])
                smallest = right;
            
            if(smallest != i)
                swap(heap[smallest], heap[i]);
            else
                break;
            i = smallest;
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.size() == 0)
            return -1;
        return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};