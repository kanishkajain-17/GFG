class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int ans = -1;
        int maxCount = 0;
        
        for (int i = 0; i < n; i += 1) {
            int count = 0;
            for (int j = 0; j < n; j += 1) {
                if(arr[i][j] == 1)
                    count += 1;
            }
            if(count > maxCount)
                ans = i;
            maxCount  = max(maxCount, count);
        } 
        return ans;
    }
};