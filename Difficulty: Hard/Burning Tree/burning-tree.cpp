/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    int findMinTime(map<Node*, Node*>& parent, Node* targetAdd){
        queue<Node*>q;
        q.push(targetAdd);
        map<Node*, int>vis;
        vis[targetAdd] = 1;
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            int fl = 0; //fl = flag
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                
                
                //checking for left
                if(node->left && !vis[node->left]){
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                //checking for right
                if(node->right && !vis[node->right]){
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                //checking for parent
                if(parent[node] && !vis[parent[node]]){
                    fl = 1;
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
            if(fl == 1)//mtlb kahi(left, right, parent) toh burn hua hai
                //bhale kahi ek jagah bhi hua ho lekin uss time mai burn hua hai
                //toh time badha dennge
                time++;
                
        }
        return time;
    }
  
    Node* addParentandAddress(Node* root, map<Node*, Node*>& parent, 
    int target){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target)//target value ka address mil gaya 
                res = node;//res mai usska address store karlo
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*>parent;
        Node* targetAdd = addParentandAddress(root, parent, target);
        int time = findMinTime(parent, targetAdd);
        return time;
        
    }
};