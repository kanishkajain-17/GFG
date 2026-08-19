/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root)
            return true;
        
        queue<Node*> que;
        que.push(root);
        
        while (!que.empty()) {
            Node* node = que.front();
            que.pop();
            
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
                que.push(node->left);
            
            if(node->right != NULL)
                que.push(node->right);
        }
        return true;
    }
};