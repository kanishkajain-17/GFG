class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = indices.size();
        int m = arr.size();
        int count = 0;
        vector<int> ans;
        
        for (int i = 0; i < n; i ++) {
            
            int target_idx = indices[i];
            int target_val = arr[target_idx];
            count = 0;
            
            for (int j = target_idx + 1; j < m; j++) {
                
                if(arr[j] > target_val)
                    count += 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};