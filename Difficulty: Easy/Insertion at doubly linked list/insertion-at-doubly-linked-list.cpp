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
        Node* newNode = new Node(x);
        
        Node* temp = head;
        
        for (int i = 0; i < p; i += 1)
            temp = temp->next;
            
        if(temp->next != NULL)
            temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        
        return head;
        
        
    }
};