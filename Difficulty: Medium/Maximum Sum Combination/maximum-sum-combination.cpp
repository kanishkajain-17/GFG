class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m = a.size();
        int n = b.size();
        
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        vector<int>ans;
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        
        pq.push({a[m - 1] + b[n - 1], {m - 1, n - 1}});
        st.insert({m - 1, n - 1});
        
        while (k--) {
            
            auto P = pq.top();
            pq.pop();
            
            int sum = P.first;
            int i = P.second.first;
            int j = P.second.second;
            
            ans.push_back(sum);
            
            if(st.find({i - 1, j}) == st.end()) {
                
                pq.push({a[i - 1] + b[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            
            if(st.find({i, j - 1}) == st.end()) {
                
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
        }
        return ans;
    } 
};