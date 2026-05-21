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
        // Code here
        if(head == NULL){
            Node *node = new Node(x);
            head = node;
            head->next = NULL;
            return node;
        }
        Node *node = new Node(x);
        node->next = head;
        head = node;
        return node;
            
    }
};