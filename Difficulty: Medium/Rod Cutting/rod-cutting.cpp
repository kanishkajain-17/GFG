// User function Template for C++

class Solution {
  public:
    //jis index par jo value hai, vahi le sakte hai
    //3 + 5 nahi bcz 3 index par 8 hai and 5 par 10 hai 8 + 10 < 22 
    int cutRod(vector<int> &nums) {
        // code here
        int n = nums.size();
        vector<int>dp(n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] = max(dp[i], nums[j] + dp[i - j - 1]);
            }
        }
        return dp[n];
    }
};