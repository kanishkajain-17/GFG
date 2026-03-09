class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt, int capacity, int i,  vector<vector<int>>&dp){
        if(i == wt.size())
            return capacity = 0;
        int take = 0;
        
        if(dp[i][capacity] != -1)
            return dp[i][capacity];
        
        if(capacity >= wt[i])
            take = val[i] + solve(val, wt, capacity - wt[i], i, dp);
        int not_take = solve(val, wt, capacity, i + 1, dp);
        
        return dp[i][capacity] = max(take, not_take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n + 1, vector<int>(capacity + 1, -1));
        return solve(val, wt, capacity, 0, dp);
    }
};