class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V);
        queue<int> que;
        int count = 0;
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v] += 1;
        }
        
        for (int i = 0; i < V; i += 1) {
            if(indegree[i] == 0) {
                que.push(i);
                count += 1;
            }
        }
        
        while (!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            for (int &v : adj[u]) {
                
                indegree[v] -= 1;
                
                if(indegree[v] == 0) {
                    count += 1;
                    que.push(v);
                }
            }
        }
        
        return !(count == V);
    }
};