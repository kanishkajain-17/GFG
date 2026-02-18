/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        if(!root)
            return 0;
        int floorr = -1;
        while(root){
            if(root->data == x)
                return root->data;
            else if(root->data < x){
                floorr = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return floorr;
    }
    
};