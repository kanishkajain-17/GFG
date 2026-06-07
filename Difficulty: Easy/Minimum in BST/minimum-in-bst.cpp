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
    int minValue(Node* root) {
        // code here
        if(root == NULL)
            return 0;
        Node* temp = root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp->data;
    }
};