// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        deque<int> dq;
        int faults = 0;
        
        for (int i = 0; i < N; i += 1) {
            auto it = find(begin(dq), end(dq), pages[i]);
            if(it != dq.end())
                dq.erase(it);
            else{
                if(dq.size() >= C)
                    dq.pop_front();
                faults += 1;
            }
            dq.push_back(pages[i]);
        }
        return faults;
    }
};