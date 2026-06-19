class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<p>> adj(V);
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans(V, INT_MAX);
        
        for (auto & e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        ans[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(wt > ans[u])
                continue;
                
            for (auto &node : adj[u]) {
                
                int adjNode = node.first;
                int dist = node.second;
                
                if(wt + dist < ans[adjNode]) {
                    ans[adjNode] = wt + dist;
                    pq.push({ans[adjNode], adjNode});
                }
            }
        }
        return ans;
    }
};