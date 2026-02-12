/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int>temp;
    void solve(Node* root){
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
    vector<vector<int>> Paths(Node* root) {
        // code here
        if(!root)
            return {};
        solve(root);
        return ans;
    }
};