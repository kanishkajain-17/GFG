class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int count = 0;
        int XOR = 0;
        
        for (int i = 0; i < n; i ++) {
            
            XOR ^= arr[i];
            
            if(XOR == k)
                count += 1;
            
            if(mp.find(k ^ XOR) != mp.end()) {
                count += mp[k ^ XOR];
            }
            mp[XOR] ++;
        }
        return count;
    }
};