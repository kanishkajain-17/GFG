class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int i, vector<vector<int>>&dp
){
       
        if(i >= arr.size())
            return (sum == 0);

        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        bool take = false; //assign take value is must as what if (sum < arr[i])
        if(sum >= arr[i])
            take = solve(arr, sum - arr[i], i + 1, dp);
            
        bool not_take = solve(arr, sum, i + 1, dp);
        
        return dp[i][sum] = take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};