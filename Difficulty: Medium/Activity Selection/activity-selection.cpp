class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        int maxEnd = -1;
        int count = 0;
        
        vector<pair<int, int>> nums;
        
        for (int i = 0; i < n;i ++)
            nums.push_back({start[i], finish[i]});
            
        auto lambda = [&] (pair<int, int> a, pair<int, int> b) {
            
            return a.second < b.second;
        };
            
        sort(begin(nums), end(nums), lambda);
        
        for (int i = 0; i < n; i ++) {
            
            if(nums[i].first > maxEnd) {
                count += 1;
                maxEnd = nums[i].second;
            }
        }
        
        return count;
    }
};