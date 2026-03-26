class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i = n - 1; i >= 1; i--){
            for(int j = i + 1; j < n; j++){
                int mini = INT_MAX;
                for(int idx = i; idx < j; idx++){
                    int count = (arr[i - 1] * arr[idx] * arr[j]) + dp[i][idx] + dp[idx + 1][j];
                    mini = min(mini, count);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};