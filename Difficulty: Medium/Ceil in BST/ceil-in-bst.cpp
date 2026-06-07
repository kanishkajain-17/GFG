/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(root == NULL)
            return -1;
        int cei = -1;
        while (root) {
            if(root->data == x)
                return root->data;
            else if (root->data > x){
                cei = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }
        return cei;
    }
};
