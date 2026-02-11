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
        if(!root)
            return {};
        vector<int>ans;
        queue<pair<Node*, int>>q; //node, level
        q.push({root, 0});
        map<int, int>mp; //vertical axis coordinate, node value
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int level = it.second;
            
            if(mp.find(level) == mp.end())
                mp[level] = node->data;
                
            if(node->left != NULL)
                q.push({node->left, level - 1});
                
            if(node->right != NULL)
                q.push({node->right, level + 1});
        }
        for(auto it : mp)
            ans.push_back(it.second);
        return ans;
    }
};