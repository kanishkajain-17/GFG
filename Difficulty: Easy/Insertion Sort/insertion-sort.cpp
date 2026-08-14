class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            
            int cur = arr[i];
            int prev = i - 1;
            
            while (prev >= 0 && arr[prev] > cur) {
                arr[prev + 1] = arr[prev];
                prev -= 1;
            }
            arr[prev + 1] = cur;
        }
    }
};