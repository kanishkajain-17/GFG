class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<p>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans(V, INT_MAX);
        
        ans[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            
            int dist = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            
            if(dist > ans[u])
                continue;
            
            for (auto &vec : adj[u]) {
                
                int node = vec.first;
                int wt = vec.second;
                
                if(dist + wt < ans[node]) {
                    
                    ans[node] = dist + wt;
                    pq.push({ans[node], node});
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};
