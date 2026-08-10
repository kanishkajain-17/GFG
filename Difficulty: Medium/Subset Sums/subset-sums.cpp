class Solution {
  public:
    vector<int> ans;
    
    void solve(vector<int>& arr, int n, int i, int sum) {
        
        if(i == n) {
            ans.push_back(sum);
            return;
        }
        
        solve(arr, n, i + 1, sum + arr[i]);
        solve(arr, n, i + 1, sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        solve(arr, n, 0, 0);
        return ans;
        
    }
};