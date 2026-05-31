class Solution {
public:

    Node* mergeTwoLists(Node* l1, Node* l2) {

        if(!l1)
            return l2;

        if(!l2)
            return l1;

        Node* ans;

        if(l1->data < l2->data) {
            ans = l1;
            ans->bottom = mergeTwoLists(l1->bottom, l2);
        }
        else {
            ans = l2;
            ans->bottom = mergeTwoLists(l1, l2->bottom);
        }

        ans->next = NULL;

        return ans;
    }

    Node* flatten(Node* head) {

        if(head == NULL || head->next == NULL)
            return head;

        Node* head2 = flatten(head->next);

        return mergeTwoLists(head, head2);
    }
};