class Solution {
  public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        
        int i = l, j = mid + 1;
        vector<int> temp(r - l + 1);   
        int k = 0;
        
        while (i <= mid && j <= r) {
            
            if(arr[i] >= arr[j]) {
                temp[k] = arr[j];
                k += 1;
                j += 1;
            }
            else {
                temp[k] = arr[i];
                k += 1;
                i += 1;
            }
        }
        while (i <= mid) {
            temp[k] = arr[i];
            i += 1;
            k += 1;
        }
        while (j <= r) {
            temp[k] = arr[j];
            j += 1;
            k += 1;
        }
        
        for (int m = 0; m < temp.size(); m++)
            arr[m + l] = temp[m];
    }
    void mergeS(vector<int>& arr, int l, int r) {
        
        if(l < r) {
            
            int mid = l + (r - l) / 2;
            mergeS(arr, l, mid);
            mergeS(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        mergeS(arr, l, r);
    }
};