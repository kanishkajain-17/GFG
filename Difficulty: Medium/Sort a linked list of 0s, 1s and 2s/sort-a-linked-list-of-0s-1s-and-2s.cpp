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
        Node* temp = head;
        int zero_count = 0;
        int one_count = 0;
        int two_count = 0;
        
        while (temp != NULL) {
            if(temp->data == 0)
                zero_count += 1;
            else if(temp->data == 1) 
                one_count += 1;
            else
                two_count += 1;
            temp = temp->next;
        }
        
        temp = head;
        while (zero_count --) {
            temp->data = 0;
            temp = temp->next;
        } 
        while (one_count --) {
            temp->data = 1;
            temp = temp->next;
        } 
        while (two_count --) {
            temp->data = 2;
            temp = temp->next;
        } 
        return head;
    }
};