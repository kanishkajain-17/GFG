class Solution {
  public:
    typedef pair<int, int> p;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<p>> adj(V);
         for (auto &e : edges) {
             int u = e[0];
             int v = e[1];
             int wt = e[2];
             
             adj[u].push_back({v, wt});
             adj[v].push_back({u, wt});
         }
         
         vector<int> visited(V, false);
         int sum = 0;
         
         priority_queue<p, vector<p>, greater<p>> pq;
         pq.push({0, 0});
         
         while (!pq.empty()) {
             
             int wt = pq.top().first;
             int node = pq.top().second;
             pq.pop();
             
             if(visited[node] == true)
                continue;
            
             visited[node] = true;
             sum += wt;
             
             for (auto &a : adj[node]) {
                 
                 int neighbour_node = a.first;
                 int neighbour_wt = a.second;
                 
                 if(visited[neighbour_node] == false) {
                     pq.push({neighbour_wt, neighbour_node});
                 }
             }
         }
         return sum;
    }
};