class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int ans = -1;
        
        while (r < n) {
            
            mp[s[r] - 'a'] += 1;
            
            while (mp.size() > k) {
                mp[s[l] - 'a'] -= 1;
                
                if(mp[s[l] - 'a'] == 0)
                    mp.erase(s[l] - 'a');
                
                l ++;
            }
            if(mp.size() == k)
                 ans = max(ans, r - l + 1);
            r += 1;
        }
        
        return ans;
    }
};