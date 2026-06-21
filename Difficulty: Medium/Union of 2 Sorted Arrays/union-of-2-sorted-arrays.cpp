class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int m = a.size();
        int n = b.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < m && j < n) {
            
            if(a[i] <= b[j]) {
                if(ans.size() == 0 || a[i] != ans.back())
                    ans.push_back(a[i]);
                i += 1;
            }
            else {
                if(ans.size() == 0 || b[j] != ans.back())
                     ans.push_back(b[j]);
                j += 1;
            }
        }
       
        while (i < m) {
            if(a[i] != ans.back())
                 ans.push_back(a[i]);
            i += 1;
        }
        while (j < n) {
            if(b[j] != ans.back())
                ans.push_back(b[j]);
            j += 1;
        }
        return ans;
    }
};