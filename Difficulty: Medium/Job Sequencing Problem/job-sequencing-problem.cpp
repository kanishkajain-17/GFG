class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = profit.size();
        vector<pair<int, int>> jobs;
        
        for (int i = 0; i < n; i += 1) {
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(begin(jobs), end(jobs));
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto &j : jobs) {
            
            int dead = j.first;
            int prof = j.second;
            
            pq.push(prof);
            if(pq.size() > dead)
                pq.pop();
        }
        int jobsDone = pq.size();
        int totalProfit = 0;
        
        while (!pq.empty()) {
            totalProfit += pq.top();
            pq.pop();
        }
        return {jobsDone, totalProfit};
    }
};