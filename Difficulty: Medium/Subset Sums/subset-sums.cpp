class Solution {
  public:
    vector<int>ans;
    void solve(vector<int>&arr, int i, int sum){
        if(i == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        solve(arr, i + 1, sum + arr[i]);
        solve(arr, i + 1, sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        solve(arr, 0, 0);
       
        return ans;
    }
};