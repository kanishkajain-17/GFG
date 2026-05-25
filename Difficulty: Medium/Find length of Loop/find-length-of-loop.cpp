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
    int lengthOfLoop(Node *head) {
        if(head == NULL || head->next == NULL)
            return 0;
        int len = 1;
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        if(slow != fast)
            return 0;
        fast = fast->next;
        while (slow != fast) {
            len += 1;
            fast = fast->next;
        }
        return len;
        
    }
};