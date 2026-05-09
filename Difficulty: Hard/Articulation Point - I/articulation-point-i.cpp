class Solution {
public:

    void dfs(int node, int parent,
             vector<int> &disc,
             vector<int> &low,
             vector<bool> &visited,
             vector<int> adj[],
             vector<int> &ap,
             int &timer) {

        visited[node] = true;

        disc[node] = low[node] = timer++;

        int child = 0;

        for(auto nbr : adj[node]) {

            // ignore parent
            if(nbr == parent)
                continue;

            // not visited
            if(!visited[nbr]) {

                dfs(nbr, node, disc, low, visited, adj, ap, timer);

                // update low value
                low[node] = min(low[node], low[nbr]);

                // articulation point condition
                if(low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }

                child++;
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // special case for root node
        if(parent == -1 && child > 1) {
            ap[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {

        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V, false);

        vector<int> ap(V, 0);

        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1, disc, low, visited, adj, ap, timer);
            }
        }

        vector<int> ans;

        for(int i = 0; i < V; i++) {
            if(ap[i] == 1)
                ans.push_back(i);
        }

        if(ans.size() == 0)
            return {-1};

        return ans;
    }
};