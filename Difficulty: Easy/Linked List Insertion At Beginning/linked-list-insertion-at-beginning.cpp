/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        Node* node = new Node(x);
        
        // Code here
        if(head == nullptr)
            return node;
        
        
        node->next = head;
        head = node;
        
        return head;
    }
};