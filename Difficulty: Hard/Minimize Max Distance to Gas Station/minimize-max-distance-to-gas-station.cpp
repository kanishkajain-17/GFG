class Solution {
  public:
     bool canPartition (vector<int> &arr, int k, double mid) {
        int count = 0;
        for (int i = 1; i < arr.size(); i += 1) {
            int dif = arr[i] - arr[i - 1];
            if(dif > mid) {
                count += dif / mid;
            }
        }
        return count <= k;
    } 
    double minMaxDist(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        double ans = 0;
        double l = 0;
        double r = *max_element(begin(arr), end(arr)); //O(log(sum(arr)))

        while (l <= r) {
            
            double mid = l + (r - l) / 2.0;
            if(canPartition (arr, k, mid)){ //O(n)
                ans = mid;
                r = mid - 0.000001;
            }
            else
                l = mid + 0.000001;
        } 
        return ans;
    }
};