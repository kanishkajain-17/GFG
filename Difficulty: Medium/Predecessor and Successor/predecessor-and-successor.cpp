/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* cei = NULL;
        Node* flo = NULL;
        while (root) {
            if(root->data < key) {
                cei = root;
                root = root->right;
            }
            else if(root->data > key) {
                flo = root;
                root = root->left;
            }
            else{
                if(root->left != NULL) {
                    Node* temp = root->left;
                    while (temp->right != NULL)
                        temp = temp->right;
                    cei = temp;
                }
                if(root->right != NULL) {
                Node* temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;
                flo = temp;
                }
                break;
                
            }
                
        }
        return {cei, flo};
    }
};