class Solution {
  public:
    bool canPlaced(vector<int> &stalls, int k, int mid) {
        int lastStall = stalls[0];
        int cows = 1;
        
        for (int i = 1; i < stalls.size(); i += 1) {
            if(stalls[i] - lastStall >= mid) {
                cows += 1;
                lastStall = stalls[i];
            }
            if(cows >= k)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(begin(stalls), end(stalls));
        int n = stalls.size();
        int l = 1;
        int r = stalls[n - 1] - stalls[0];
        //The maximum possible minimum distance can never exceed:
        //because that's the distance between the leftmost and rightmost stall.
        
        int minDistance = 0;
        int ans = 0;
        //2 cows ke bich ka min distance 1 toh rahega he 
        //isly l = 1
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(canPlaced(stalls, k, mid)){
                ans = mid;
                l = mid + 1; //this time we need to find larger distances
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};