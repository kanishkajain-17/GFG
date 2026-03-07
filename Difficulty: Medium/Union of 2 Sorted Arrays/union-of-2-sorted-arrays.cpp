class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int>ans;
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        
        while(i < m && j < n){
            
            if(a[i] <= b[j]){
                if(ans.size() == 0 || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            }
            else{
                if(ans.size() == 0 || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i < m){
            if(ans.size() == 0 || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        
        while(j < n){
            if(ans.size() == 0 || ans.back() != b[j])
                    ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};