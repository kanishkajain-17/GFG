/* Structure of linked list Node
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
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* cur = head;
        Node* nextt = NULL;
        
        while (cur != NULL) {
            nextt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextt;
        }
        return prev;
        
    }
    Node* addOne(Node* head) {
        // code here
        if(head == NULL)
            return NULL;
            
        if(head->next == NULL){
            head->data += 1;
            return head;
        }
            
        head = reverse(head);
        
        if(head->data < 9){
            head->data += 1;
            head = reverse(head);
            return head;
        }
        
        Node* temp = head;
        Node* prev = head;
        while (temp != NULL && temp->data == 9) {
            
            temp->data = 0;
            
            if(temp->next == NULL) {
                Node* node = new Node(1);
                temp->next = node;
                head = reverse(head);
                 return head;
            }
            temp = temp->next;
        }
        
           
        temp->data += 1;
        head = reverse(head);
        return head;
    }
};