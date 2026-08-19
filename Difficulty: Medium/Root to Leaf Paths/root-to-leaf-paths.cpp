/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>>ans;
    vector<int> temp;
    void solve(Node* root) {
        
        if(!root)
            return;
        temp.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL)
            ans.push_back(temp);
        
        else{
            solve(root->left);
            solve(root->right);
        }
        temp.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        if(!root)
            return {};
        solve(root);
        return ans;
    }
};