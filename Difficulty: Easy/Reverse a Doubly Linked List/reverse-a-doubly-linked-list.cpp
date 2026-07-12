/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        
        Node* prev = NULL;
        Node *cur = head;
        Node *next = NULL;
        
        while (cur != NULL) {
            
            next = cur->next;
            
            cur->next = prev;
            cur->prev = next;
            
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};