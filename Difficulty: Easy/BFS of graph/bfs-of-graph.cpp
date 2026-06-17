class Solution {
  public:
    vector<int> ans;
    void findBfs(vector<vector<int>> &adj, vector<bool> &visited) {
        queue<int> que;
        que.push(0);
        visited[0] = true;
        ans.push_back(0);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            
            for (int &v : adj[u]) {
                if(visited[v] == false){
                    visited[v] = true;
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> visited(n, false);
        findBfs(adj, visited);
        return ans;
    }
};