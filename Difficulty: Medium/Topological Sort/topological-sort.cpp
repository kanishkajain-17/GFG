class Solution {
  public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited,
        stack<int> &st, int u) {
            
            if(visited[u] == true)
                return;
            visited[u] = true;
            
            
            for (int &v: adj[u]) {
                if(visited[v] == false) 
                    dfs(adj, visited, st, v);
            }
            st.push(u);
        } 
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        vector<int> ans;
        vector<bool> visited(V, false);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i ++)
            if(visited[i] == false)
                dfs(adj, visited, st, i);
        
        while (!st.empty()) {
            
            ans.push_back(st.top());
            st.pop();
            
        }
        
        return ans;
        
    }
};