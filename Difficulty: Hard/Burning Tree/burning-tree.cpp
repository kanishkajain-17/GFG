/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, Node* cur) {
        
        if(cur == NULL)
            return;
        
        if(parent != -1) 
            adj[cur->data].push_back(parent);
            
        if(cur->left != NULL)
            adj[cur->data].push_back(cur->left->data);
            
        if(cur->right != NULL)
            adj[cur->data].push_back(cur->right->data);
            
        makeGraph(adj, cur->data, cur->left);
        makeGraph(adj, cur->data, cur->right);
        
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);
        
        unordered_set<int> visited;
        visited.insert(target);
        
        queue<int> que;
        que.push(target);
        
        int seconds = 0;
        
        while (!que.empty()) {
            
            int n = que.size();
            
            while (n--) {
                
                int cur = que.front();
                que.pop();
                
                for (int &ngbr : adj[cur]) {
                    
                    if(visited.count(ngbr) == 0) {
                        visited.insert(ngbr);
                        que.push(ngbr);
                    }
                }
            } 
            seconds += 1;
        }
        
        return seconds - 1;
    }
};