class Solution {
  public:
    bool solve(vector<int>& arr, int target, int i){
        if(target < 0)
            return false;
        if(i >= arr.size())
            return target == 0;

        // take OR not take
        return solve(arr, target - arr[i], i + 1) || 
               solve(arr, target, i + 1);
    }
    
    bool checkSubsequenceSum(vector<int>& arr, int k){
        return solve(arr, k, 0);
    }
};