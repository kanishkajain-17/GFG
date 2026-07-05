class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i <= n - 3; i ++) {
            
            unordered_map<int, int> mp;
            bool flag = false;
            
            for (int j = i; j < n; j ++) {
                
                mp[s[j]] += 1;
                
                if(mp.size() == 3) {
                    
                    count += n - j;
                    flag = true;
                } 
                
                if(flag == true)  
                    break;
            }
        }
        return count;
    }
};