class Solution {
  public:
    int countFreq(vector<int>& nums, int x) {
        // code here
        int n = nums.size();
        int left = -1;
        int right = -1;
        int l = 0, r = n - 1;
        
        //alag alag calculate kar rahe hai
        //leftMost
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == x) {
                left = mid;
                r = mid - 1;
            }
            else if(nums[mid] > x)  
                r = mid - 1;
            else
                l = mid + 1;
        }

        //rightMost
        l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == x) {
                right = mid;
                l = mid + 1;
            }
            else if(nums[mid] > x)  
                r = mid - 1;
            else
                l = mid + 1;
        }
        if(left == - 1 && right == -1)
            return 0;
        return right - left + 1;
    }
};
