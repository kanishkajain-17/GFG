/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        Node* temp = head;
        Node* prevv = NULL;
        if(x == 1) {
            head->next->prev = NULL;
            head = head->next;
            delete(temp);
            return head;
        }
        
        for (int i = 1; i < x; i += 1) {
            prevv = temp;
            temp = temp->next;
            
        }
        prevv->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = prevv;
        return head;
    }
};