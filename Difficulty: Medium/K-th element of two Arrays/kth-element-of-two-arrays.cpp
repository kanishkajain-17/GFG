class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i = 0, j = 0;
        int m = a.size();
        int n = b.size();
       
        while (i < m && j < n) {
           if(a[i] < b[j]) {
               k -= 1;
               if(k == 0)
                    return a[i];
                i += 1;
           }
           else{
               k -= 1;
               if(k == 0)
                    return b[j];
                j += 1;
           }
        }
        while (i < m) {
         k -= 1;
           if(k == 0)
                return a[i];
            i += 1;
        }
        while (j < n) {
         k -= 1;
           if(k == 0)
                return b[j];
            j += 1;
        }
        return -1;
    }
};