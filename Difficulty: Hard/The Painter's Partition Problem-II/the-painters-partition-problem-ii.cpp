class Solution {
  public:
    bool canPaint(vector<int>& arr, int mid, int k) {

        int n = arr.size();    
        int timee = 1;
        int sum = 0;

        for (int i = 0; i < n; i ++) {

            sum += arr[i];
            
            if(sum > mid) {
                timee += 1;
                sum = arr[i];
            }
        }
        return timee <= k;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
         int n = arr.size();
        
        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0);
        int ans = 0;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(canPaint (arr, mid, k)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};