class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
         if(!root)
            return 0;
        int cei = -1;
        while(root){
            if(root->data == x)
                return root->data;
            else if(root->data > x){
                cei = root->data;
                root = root->left;
                
            }
            else{
                
                root = root->right;
                
                
            }
        }
        return cei;
    }
};
