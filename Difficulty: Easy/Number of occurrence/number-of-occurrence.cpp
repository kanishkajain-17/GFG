class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        int flor = n, cei = -1;
        int l = 0, r = n - 1;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(nums[mid] <= target) {
                cei = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = 0, r = n - 1;
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(nums[mid] >= target) {
                flor = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
                
        }
        if(flor == n && cei == -1)
            return 0;
        return cei - flor + 1;
    }
};
