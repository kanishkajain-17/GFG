class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        
        for (int i = 0; i < n; i ++) {
            pq.push(arr[i]);
        }
        int i = 0;
        while (!pq.empty() && i < n) {
            arr[i] = pq.top();
            pq.pop();
            i += 1;
        }
        
    }
};