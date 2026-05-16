class Solution {
  public:

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = profit.size();

        vector<pair<int,int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({deadline[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : jobs) {

            int dead = it.first;
            int prof = it.second;

            pq.push(prof);

            if(pq.size() > dead) {
                pq.pop();
            }
        }

        int totalProfit = 0;
        int jobsDone = pq.size();

        while(!pq.empty()) {
            totalProfit += pq.top();
            pq.pop();
        }

        return {jobsDone, totalProfit};
    }
};