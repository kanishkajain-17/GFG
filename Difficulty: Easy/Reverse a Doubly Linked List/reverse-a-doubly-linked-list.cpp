/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* prevv = NULL;
        Node* cur = head;
        Node* nextt = NULL;
        
        while (cur != NULL) {
            nextt = cur->next;
            cur->next = prevv;
            prevv = cur;
            cur = nextt;
        }
        return prevv;
    }
};