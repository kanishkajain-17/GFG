class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        for (int i = 0; i < n; i ++)
            jobs.push_back({deadline[i], profit[i]});
            
        sort(begin(jobs), end(jobs));
            
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto &p : jobs) {
            
            int dead = p.first;
            int prof = p.second;
            
            pq.push(prof);
            
            if(pq.size() > dead)
                pq.pop();
                
        }
        int totalJobs = pq.size();
        
        int totalProf = 0;
        
        while (!pq.empty()) {
            
            totalProf += pq.top();
            pq.pop();
        }
        
        return {totalJobs, totalProf};
    }
};