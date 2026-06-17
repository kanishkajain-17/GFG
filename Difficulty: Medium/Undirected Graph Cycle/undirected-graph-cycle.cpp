class Solution {
  public:
     bool bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, int parent) {
            
        queue<pair<int, int>> que;
        que.push({u, parent});
        
        visited[u] = true;
        
        while (!que.empty()) {
            pair<int, int> P = que.front();
            int u = P.first;
            int parent = P.second;
            que.pop();
            
            for (int &v : adj[u]) {
                
                if(visited[v] == true) {
                    if(v != parent)
                        return true;
                }
                else{
                    visited[v] = true;
                    que.push({v, u});
                }
            }
        }
        return false;
     }
           
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
         unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i ++) 
            if(!visited[i] &&  bfs(adj, visited, i, -1))
                return true;
        return false;
    }
};