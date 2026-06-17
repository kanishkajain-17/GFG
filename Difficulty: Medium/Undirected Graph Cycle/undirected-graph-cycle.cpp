class Solution {
  public:
    bool dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, int parent) {
            
            visited[u] = true;
            for (int &v : adj[u]) {
                if(visited[v] == true){
                    if(v != parent)
                        
                        return true;
                }
                else
                    if(dfs(adj, visited, v, u))
                        return true;
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
            if(!visited[i] &&  dfs(adj, visited, i, -1))
                return true;
        return false;
    }
};