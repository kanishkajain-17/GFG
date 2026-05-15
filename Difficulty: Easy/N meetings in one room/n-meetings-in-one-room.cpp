class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i += 1) {
            arr.push_back({start[i], end[i]});
        }
        
        auto lambda = [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        };
        
        sort(arr.begin(), arr.end(), lambda);
        
         int count = 1;
        int prev = arr[0].second;
        
        for (int i = 1; i < n; i += 1) {
            if(arr[i].first > prev){
                count += 1;
                prev = arr[i].second;
            }
        }
        return count;
    }
};