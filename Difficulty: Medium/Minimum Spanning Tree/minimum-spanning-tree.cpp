class Solution {
  public:
    typedef pair<int, int>P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<P>>adj(V);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, 0}); //{wt, node}
        vector<int>inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node] == true)
                continue;
            inMST[node] = true;
            sum += wt;
            
            for(auto & vec : adj[node]){ // uss node se aage dekho kon
                //kon connected hai phir udher explore karo
                int neighbour = vec.first;
                int neighbour_wt = vec.second;
                
                if(inMST[neighbour] == false)
                    pq.push({neighbour_wt, neighbour});
            }
        }
        return sum;
    }
};