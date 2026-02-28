class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int maxi = 0;
        
        vector<int>dp1(n, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp1[i] < dp1[j] + 1)
                        dp1[i] = dp1[j] + 1;
                }
            }
        }
        
        vector<int>dp2(n, 1);
        for(int i = n - 2; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j]){
                    if(dp2[i] < dp2[j] + 1)
                        dp2[i] = dp2[j] + 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dp1[i] > 1 && dp2[i] > 1)//strictly increasing or decreasing 
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        return maxi;
    }
};
