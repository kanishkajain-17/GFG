/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* temp = head;
        Node* prevv = NULL;
        unordered_set<int> st;
        
        while (temp != NULL) {
            
            int val = temp->data;
            
            if(st.find(val) != st.end()) {
                prevv->next = temp->next;
                if(temp->next != NULL) 
                    temp->next->prev = prevv;
                Node* cur = temp;
                temp = temp->next;
                delete(cur);
            }
            else{
                st.insert(val);
                prevv = temp;
                temp = temp->next;
            }
                
        }
        return head;
    }
};