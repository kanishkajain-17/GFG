class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        
        int n = arr.size();
        int maxi = 0;
        int count = 0;
        int i = 0, j = 0;
        
        while (i < n) {
            if(arr[i] <= dep[j]) {
                count += 1;
                maxi = max(maxi, count);
                i += 1;
            }
            else{
                count -= 1;
                j += 1;
            }
        }
        return maxi;
    }
};
