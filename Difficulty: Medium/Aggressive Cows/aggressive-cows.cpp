class Solution {
  public:
    bool canPlaced(vector<int> &stalls, int mid, int k) {
        
        int cows = 1;
        int lastStall = stalls[0];
        int n = stalls.size();
        
        for (int i = 1; i < n; i ++) {
            
            if(stalls[i] - lastStall >= mid) {
                lastStall = stalls[i];
                cows += 1;
            }
            
            if(cows > k)
                break;
        }
        return cows >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(begin(stalls), end(stalls));
        int n = stalls.size();
        int l = 1;
        int r = stalls[n - 1] - stalls[0];
        int ans = 0;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(canPlaced(stalls, mid, k)){
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};