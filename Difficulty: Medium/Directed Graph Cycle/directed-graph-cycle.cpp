class Solution {
  public:
     bool dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, 
        vector<bool> &inRecursion, int u) {
            
            visited[u] = true;
            inRecursion[u] = true;
            
            for (int &v : adj[u]) {
                if(visited[v] == true){
                    if(inRecursion[v] == true)
                         return true;
                }
                else
                    if(!visited[v] && dfs(adj, visited, inRecursion, v))
                        return true;
            }
            inRecursion[u] = false;
            return false;
        }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for (int i = 0; i < n; i ++) 
            if(!visited[i] &&  dfs(adj, visited, inRecursion, i))
                return true;
        return false;
    }
};