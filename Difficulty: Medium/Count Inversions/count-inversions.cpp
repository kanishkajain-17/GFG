class Solution {
  public:
    int merge(vector<int> &arr, int st, int mid, int end) {
        
        vector<int> temp;
        int i = st, j = mid + 1;
        int invCount = 0;
        
        while (i <= mid && j <= end) {
            
            if(arr[i] <= arr[j]) {
                
                temp.push_back(arr[i]);
                i += 1;
            }
            else{
                   temp.push_back(arr[j]);
                   j += 1;
                   invCount += mid - i + 1;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
                i += 1;
        }
        while (j <= end) {
            temp.push_back(arr[j]);
                   j += 1;
        }
        
        for (int i =0; i < temp.size(); i ++) {
            
            arr[st + i] = temp[i];
        }
        return invCount;
    }
    int mergeSort(vector<int> &arr, int st, int end) {
        
        if(st < end) {
            
            int mid = st + (end - st) / 2;
            
            int leftInvCount = mergeSort(arr, st, mid);
            int rightInvCount = mergeSort(arr, mid + 1, end);
            
            int invCount = merge(arr, st, mid, end);
            
            return leftInvCount + rightInvCount + invCount;
            
        }
        return 0;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};