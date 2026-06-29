class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l = 1, r = n;
        int ans = 1;
        while (l <= r) {
            int mid = l + (r - l )/2;
            if(mid * mid <= n) {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};