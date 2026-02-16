// User function Template for C++
class Solution {
  public:
    vector<vector<int>>directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int>parent;
    vector<int>rank;
    
    int find(int i){
        if(parent[i] == i)
            return parent[i];
        return parent[i] = find(parent[i]);
    }

    void unionn(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;

        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;

        else{
             parent[x_parent] = y_parent;
             rank[y_parent]++;
        }
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        parent.resize(n * m);
        rank.resize(n * m, 0);
        for(int i = 0; i < n * m; i++)
            parent[i] = i;
        
        vector<vector<int>>vis(n, vector<int>(m));
        int count = 0;
        vector<int>ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;
            
            for(auto & dir : directions){
                int row_ = row + dir[0];
                int col_ = col + dir[1];
                
                if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < m){
                    if(vis[row_][col_] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = row_ * m + col_;
                        
                        if(find(nodeNo) != find(adjNodeNo)){
                            count--;
                            unionn(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
