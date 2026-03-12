class Solution {
  public:
    int maxLength(vector<int>& nums) {
        // code here
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            
            sum += nums[i];
            
            if(sum == 0)
                count = i + 1;
            
            if(mp.find(sum) != mp.end())
                count = max(count, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return count;
    }
};