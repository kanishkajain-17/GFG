class Solution {
  public:
    int minCost(vector<int>& h) {
        // Code here
        int n = h.size();
        int ans = 0;
        int prevPrev = 0;
        int prev = 0;
        int curr = 0;
        
        for(int i = 1; i < n; i++){
            int first = prev + abs(h[i - 1] -  h[i]);
        
            int second =  INT_MAX;
            if(i > 1)
                second = prevPrev + abs(h[i] -  h[i - 2]);
            
            curr = min(first, second);
            
            prevPrev = prev;
            prev = curr;
        }
        return prev;
        
    }
};