class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
        int n = nums.size();
        unordered_map<int, int>mp;
        mp.insert({0, 1});
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k)    
                maxLen = max(maxLen, i + 1);
            if(mp.find(sum - k) != mp.end()){
                int len = i - mp[sum - k];
                maxLen = max(maxLen, len);
            }
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return maxLen;
        
    }
};