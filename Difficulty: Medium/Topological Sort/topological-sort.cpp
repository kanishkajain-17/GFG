class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> ans;
        vector<int> indegree(V);
        queue<int> que;
        unordered_map<int, vector<int>> adj;
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v] += 1;
        }
       
       for(int i = 0; i < V; i ++){
           if(indegree[i] == 0) {
               ans.push_back(i);
               que.push(i);
           }
       }
        
        while (!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            for (int &v : adj[u]) {
                
                indegree[v] -= 1;
                if(indegree[v] == 0) {
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};