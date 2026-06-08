// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& nums, int x) {
        // code here
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= x){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};