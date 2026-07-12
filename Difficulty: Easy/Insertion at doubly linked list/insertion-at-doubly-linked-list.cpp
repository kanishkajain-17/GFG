/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node *node = new Node(x);
        
        if(head == NULL)
            return node;
        
        Node *prev = NULL;
        Node *temp = head;
            
        for (int i = 0; i <= p; i ++) {
            
            prev = temp;
            temp = temp->next;
        }
        
        if(temp == NULL) {
            
            prev->next = node;
            node->prev = prev;
            
            return head;
        }
        
        node->next = temp;
        temp->prev = node;
        prev->next = node;
        node->prev = prev;
        
        return head;
    }
};