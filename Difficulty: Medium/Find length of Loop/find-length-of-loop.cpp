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
        // code here
        
         if(head == NULL || head->next == NULL)
            return 0;
        
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }
        
        if(slow != fast) //never met means no cycle is present
            return 0;
            
        int len = 1;

        fast = fast->next;
        
        while (slow != fast) {
            fast = fast->next;
            len += 1;
        }
        return len;
    }
};