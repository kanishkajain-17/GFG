class Solution {
  public:
    int upperBound(vector<int> &nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = n;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > x){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        int l = INT_MAX;
        int r = INT_MIN;
        
        for (int i = 0; i < m; i ++) {
            l = min(l, mat[i][0]);
            r = max(r, mat[i][n - 1]);
        }
        
        int median_idx  = (m * n) / 2;
       
        
        while (l <= r) {
            int assumed_median = l + (r - l) / 2;
            
            int count_ele_less_or_equal_to_assumed_median = 0;
            for (int i = 0; i < m; i ++)
                
                 count_ele_less_or_equal_to_assumed_median += 
                            upperBound(mat[i], assumed_median);
                            
            if(count_ele_less_or_equal_to_assumed_median <= median_idx)
                l = assumed_median + 1;
            else
                r = assumed_median - 1;
        }
        return l;
    }
};
