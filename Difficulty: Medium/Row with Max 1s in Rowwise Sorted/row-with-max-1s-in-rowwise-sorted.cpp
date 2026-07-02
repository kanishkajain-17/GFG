class Solution {
  public:
    int findOcc(vector<int> nums, int x) {
        
        int n = nums.size();
        int flo = -1;
        
        int l = 0, r = n - 1;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(nums[mid] >= x) {
                flo = mid;
                r = mid - 1;
            }
            else
               l = mid + 1;
        }
        
        if(flo == -1)
            return -1;
            
        return n - flo;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int len = -1;
        int maxLen = -1;
        int idx = -1;
        
        for (int i = 0; i < n; i ++) {
            
            len = findOcc(arr[i], 1);

            if(len > maxLen) {
                maxLen = len;
                idx = i;
            }
        }
        return idx;
    }
};