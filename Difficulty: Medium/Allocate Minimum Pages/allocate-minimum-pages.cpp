class Solution {
  public:
    bool canAllocate(vector<int> &arr, int mid, int k) {
        
        int sum = 0;
        int student = 1;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            
            sum += arr[i];
            
            if(sum > mid) {
                student += 1;
                sum = arr[i];
            }
            
        }
        return student <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)
            return -1;
        
        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0);
        int ans = 0;
        
        while (l <= r) {
            
            int mid = l + (r - l) / 2;
            
            if(canAllocate (arr, mid, k)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};