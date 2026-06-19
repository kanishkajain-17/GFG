class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<p>> adj(n + 1);
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        int total = 0;
        
        for (int i = 0; i <= n; i ++) 
            parent[i] = i;
        
        for (auto & e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        pq.push({0, 1});
        ans[1] = 0;
        
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
                    parent[node] = u;
                    total += ans[node];
                }
            }
        }
        if(ans[n] == INT_MAX)
            return {-1};
            
        int destNode = n;
        vector<int> path(n + 1);
      
        while (destNode != parent[destNode]) {
            path.push_back(destNode);
            destNode = parent[destNode];
        }
        path.push_back(1);
        reverse(begin(path), end(path));
        path.insert(begin(path), ans[n]);
        
        return path;
    }
};