class Solution {
  public:
    int solve(vector<int>& nums, int x, int i, vector<vector<int>>& dp){
        if(i == nums.size())
            return x == 0;
        if(dp[i][x] != -1)
            return dp[i][x];
        int take = 0;
        if(x >= nums[i])
            take = solve(nums, x - nums[i], i + 1, dp);
        int not_take = solve(nums, x, i + 1, dp);
        
        return dp[i][x] = take + not_take;
    }
    int perfectSum(vector<int>& nums, int x) {
        // code here
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(x + 1, -1));
        return solve(nums, x, 0, dp);
    }
};