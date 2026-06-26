class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int len = 0;
        int maxLen = 0;
        int sum = 0;
      //  mp[0] = 1;
        
        for (int i = 0; i < n; i ++) {
            
            sum += arr[i];
            if(sum == 0)
                maxLen = i + 1;
            if(mp.find(sum) != mp.end()) {
                len = i - mp[sum];
                maxLen = max(len, maxLen);
            }
            else
                mp[sum] = i;
            
        }
        return maxLen;
    }
};