/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        if(head == NULL)
            return false;
        Node* temp = head;
        while (temp != NULL) {
            if(temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};
