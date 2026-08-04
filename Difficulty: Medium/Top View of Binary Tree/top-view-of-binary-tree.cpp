/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*, int>> que;
        que.push({root, 0});
        
        map<int,int> mp;
        
        while (!que.empty()) {
            
            auto P = que.front();
            que.pop();
            
            Node* node = P.first;
            int col = P.second;
            
            if(mp.find(col) == mp.end()) 
                mp[col] = node->data;
                
            if(node->left != NULL)
                que.push({node->left, col - 1});
                
            if(node->right != NULL)
                que.push({node->right, col + 1});
        }
        
        vector<int> ans;
        for (auto &it : mp) {
            
            ans.push_back(it.second);
        }
        return ans;
    }
};