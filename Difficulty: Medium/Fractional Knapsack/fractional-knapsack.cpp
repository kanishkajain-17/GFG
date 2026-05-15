class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<pair<int, int>> nums;
        
        for (int i = 0; i < n; i += 1) {
            nums.push_back({val[i], wt[i]});
        }
        
        auto lambda = [](pair<int, int> nums1, pair<int, int> nums2) {
            return ((double)nums1.first / nums1.second) > ((double)nums2.first / nums2.second);
        };
        sort(begin(nums), end(nums), lambda);
        double cost = 0;
        
        for (int i = 0; i < n; i += 1) {
            
            int value = nums[i].first;
            int weight = nums[i].second;
            
            if(weight <= capacity) {
                capacity -= weight;
                cost += value;
            }
            else {
                cost += ((double)capacity / weight) * value;
                break;
                
            }
        }
        return cost;
    }
};
