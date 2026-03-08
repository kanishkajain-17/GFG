

class Solution {
  public:
    vector<int> leaders(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[n - 1]);
        for(int i = n - 1; i >= 0; i--){
            if(nums[i - 1] >= nums[i] && nums[i - 1] >= ans.back())
                ans.push_back(nums[i - 1]);
        }
        reverse(begin(ans), end(ans));
        return ans;
        
    }
};