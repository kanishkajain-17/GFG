class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = n / 2 - 1; i >= 0; i -= 1) {
            
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            

            if(left < arr.size() && arr[left] > arr[i])
                return false;
                
            if(right < arr.size() && arr[right] > arr[i])
                return false;
                
        }
        return true;
    }
};
