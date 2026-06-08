class Solution {
  public:
    int upperBound(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = n;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else if(nums[mid] <= target) {
                l = mid + 1;
            }
        }
        return ans;
    }
};
