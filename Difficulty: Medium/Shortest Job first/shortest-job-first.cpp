class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        
        sort(begin(bt), end(bt));
        vector<int>completionTime(n, 0);
        completionTime[0] = bt[0];
        
        for (int i = 1; i < n; i += 1) {
            completionTime[i] = bt[i] + completionTime[i - 1];
        }
        
        vector<int> waitingTime(n, 0);
        
        for (int i = 0; i < n; i += 1) {
            waitingTime[i] = completionTime[i] - bt[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            ans += waitingTime[i];
        }
        return ans / n;
    }
};