/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int flo = -1;
        if(root == NULL)
            return -1;
        while (root) {
            if(root->data == k) 
                return k;
            else if(root->data > k)
                root = root->left;
            else{
                flo = root->data;
                root = root->right;
            }
        }
        return flo;
    }
};