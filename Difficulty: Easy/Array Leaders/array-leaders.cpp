class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;
        
        ans.push_back(arr[n - 1]);
        
        for (int i = n - 2; i >= 0; i -= 1) {
            
            if(arr[i] >= ans.back()) 
                ans.push_back(arr[i]);
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};