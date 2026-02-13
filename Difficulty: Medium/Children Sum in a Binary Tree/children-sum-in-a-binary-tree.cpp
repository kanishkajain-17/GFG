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
    bool isSumProperty(Node *root) {
        // code here
        if(!root)
            return true;
        queue<Node*>q;
        q.push(root);
        
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node->left == NULL && node->right == NULL)
                return true;
            
            int sum = 0;
            if(node->left != NULL)
                sum += node->left->data;
            if(node->right != NULL)
                sum += node->right->data;
                
            if(node->data != sum)
                return false;
                
            
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        return true;
    }
};