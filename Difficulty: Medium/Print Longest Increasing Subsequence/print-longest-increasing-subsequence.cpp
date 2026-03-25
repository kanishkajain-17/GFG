class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>prev_idx(n, -1);
        int maxLen = 1;
        int last_chosen_index = 0;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                    if(dp[i] > maxLen){
                        maxLen = dp[i];
                        last_chosen_index = i;
                    }
                }
            }
        }
        vector<int>ans;
        while(last_chosen_index != -1){
            ans.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};