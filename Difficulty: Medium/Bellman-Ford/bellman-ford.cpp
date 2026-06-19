class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int> ans(V, 1e8);
        ans[src] = 0;
        for (int i = 0; i < V; i += 1 ) {
            
            for (auto &e : edges) {
                
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                
                if(ans[u] != 1e8 && wt + ans[u] < ans[v]) {
                    ans[v] = wt + ans[u];
                }
            }
     }
     
         for (auto &e : edges) {
                
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                
                if(ans[u] != 1e8 && wt + ans[u] < ans[v]) {
                    return {-1};
                }
            } 
        return ans;
    }
};
