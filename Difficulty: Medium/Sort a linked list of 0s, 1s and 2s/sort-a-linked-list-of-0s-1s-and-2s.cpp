/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int zero = 0;
        int one = 0;
        int two = 0;
        
        Node *temp = head;
        
        while (temp != NULL) {
            
            if(temp->data == 0)
                zero += 1;
            else if(temp->data == 1)
                one += 1;
            else
                two += 1;
                
            temp = temp->next;
        }
        
        temp = head;
        
        while (zero--) {
            temp->data = 0;
            temp = temp->next;
        }
        while (one--) {
            temp->data = 1;
            temp = temp->next;
        }
        while (two--) {
            temp->data = 2;
            temp = temp->next;
        }
        
        return head;
    }
};