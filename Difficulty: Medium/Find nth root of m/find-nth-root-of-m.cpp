class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l = 1, r = m;
        if(m == 0)
            return 0;
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(pow(mid, n) == m)
                return mid;
            else if(pow(mid, n) > m)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};