// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
         vector<vector<pair<int, int>>>adj(V);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});

        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        vector<int>result(V, INT_MAX);
        result[0] = 0;
        pq.push({0, 0}); // pushing source node with its own 
                        //distnace of 0
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(d > result[node])
                continue;
                
            for(auto & vec : adj[node]){ // adj is pair<int, int>
                int adjNode = vec.first;
                int wt = vec.second;
                
                if(d + wt < result[adjNode]){
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        for(int i = 0; i < V; i++)
            if(result[i] == INT_MAX)
                result[i] = -1;
        return result;
        
    }
};
