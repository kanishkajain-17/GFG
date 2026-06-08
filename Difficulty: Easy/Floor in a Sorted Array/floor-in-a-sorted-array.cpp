class Solution {
  public:
    int findFloor(vector<int>& nums, int target) {
        // code here
        int ans = -1;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target) {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};
