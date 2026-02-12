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
    //USING DFS
    vector<int> leftView(Node *root) {
        // code here
        if(!root)
            return {};
        vector<int>ans;
        queue<Node*>que;
        
        que.push(root);
        while(!que.empty()){
            Node * node = NULL;
            int N = que.size();
            
            while(N--){
                node = que.front();
                que.pop();
                
                if(node->right != NULL)
                    que.push(node->right);
                if(node->left != NULL)
                    que.push(node->left);
            }
            ans.push_back(node->data);
        }
        return ans;
    }
};