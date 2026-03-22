class Solution {
  public:
    int merge(vector<int> &arr, int start, int mid, int end){
        vector<int> temp;
        int i = start, j = mid + 1;
        int invCount = 0;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
                invCount += (mid - i) + 1;
            }
        }
        while(i <= mid){
             temp.push_back(arr[i]);
                i++;
        }
        while(j <= end){
             temp.push_back(arr[j]);
                j++;
        }
        
        for(int idx = 0; idx < temp.size(); idx++)
            arr[idx + start] = temp[idx];
            
        return invCount;
        
    }
    int mergeSort(vector<int> &arr, int start, int end){
        if(start < end){
            
        int mid = start + (end - start) / 2;
        
        int leftInvCount = mergeSort(arr, start, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);
        
        int invCount = merge(arr, start, mid, end);
        
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