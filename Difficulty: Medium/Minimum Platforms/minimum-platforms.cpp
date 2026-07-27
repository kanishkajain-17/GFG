class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        
        int i = 0, j = 0;
        int maxi = 0;
        int count = 0;
        
        while (i < n) {
            
            if(dep[j] >= arr[i]) {
                
                count += 1;
                maxi = max(maxi, count);
                i += 1;
                
            }
            else {
                j += 1;
                count -= 1;
            }
        }
        return maxi;
        
    }
};
