class Solution {
  public:
    bool solve(vector<int>& nums, int sum, int i, vector<vector<int>>& dp){
        
            
        if(i == nums.size()){
            return sum == 0;
        }
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        bool take = false;
        if(sum >= nums[i])
            take = solve(nums, sum - nums[i], i + 1, dp);
            
        bool not_take = solve(nums, sum, i + 1, dp);
    
        return dp[i][sum] =  take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};