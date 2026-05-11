class minHeap {

private:

    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

public:

    // Insert element into heap
    void push(int x) {

        // Add element at end
        heap.push_back(x);

        int i = heap.size() - 1;

        // Move upward until heap property is satisfied
        while(i > 0 && heap[parent(i)] > heap[i]) {

            swap(heap[parent(i)], heap[i]);

            i = parent(i);
        }
    }

    // Remove minimum element
    void pop() {

        // If heap is empty
        if(heap.empty())
            return;

        // Put last element at root
        heap[0] = heap.back();

        // Remove last element
        heap.pop_back();

        int i = 0;

        // Heapify Down
        while(true) {

            int l = left(i);
            int r = right(i);

            int smallest = i;

            if(l < heap.size() && heap[l] < heap[smallest])
                smallest = l;

            if(r < heap.size() && heap[r] < heap[smallest])
                smallest = r;

            // Heap property satisfied
            if(smallest == i)
                break;

            swap(heap[i], heap[smallest]);

            i = smallest;
        }
    }

    // Return minimum element
    int peek() {

        if(heap.empty())
            return -1;

        return heap[0];
    }

    // Return size of heap
    int size() {

        return heap.size();
    }
};