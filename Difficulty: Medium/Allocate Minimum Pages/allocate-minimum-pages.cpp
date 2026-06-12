class Solution {
  public:
    bool canFind(vector<int> &arr, int k, int mid) {
        int student = 1;
        int sum = 0;
        for (int &x : arr) {
            if(sum + x > mid) {
                student += 1;
                sum = x;
            }
            else
                sum += x;
        }
        return (student <= k);
    } 
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k)
            return -1;
        int ans = 0;
        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0);
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(canFind(arr, k, mid)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        } 
        return ans;
    }
};