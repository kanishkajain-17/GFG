class Solution {
  public:
  
    vector<int> ans;
    
    void findDfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
        if(visited[u] == true)
            return;
        visited[u] = true;
        ans.push_back(u);
        for (int &v : adj[u]) {
            if(visited[v] == false) 
                findDfs(adj, visited, v);
        }
        
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        findDfs(adj, visited, 0);
        return ans;
    }
};