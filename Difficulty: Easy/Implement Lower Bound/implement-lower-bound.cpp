class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int ans = n;
        int l = 0, r = n - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if(arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
