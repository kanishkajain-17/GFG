class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        double maxVal = 0;
        
        vector<pair<int, int>> nums;
        
        for (int i = 0; i < n; i++) {
            nums.push_back({val[i], wt[i]});
        }
        
        auto lambda = [&] (pair<int, int> a, pair<int, int> b) {
            
            return ((double)a.first / a.second) > ((double)b.first / b.second); 
        };
        
        sort(begin(nums), end(nums), lambda);
        
        for (int i = 0; i < n; i++) {
            
            int value = nums[i].first;
            int wtt = nums[i].second;
            
            if(wtt <= capacity) {
                
                maxVal += value;
                capacity -= wtt;
            }
            else {
                
                maxVal += ((double)capacity / wtt) * value;
                break;
            }
        }
        return maxVal;
    }
};
