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
        vector<int> sorted_values;
        Node* temp = head;
        while (temp != NULL) {
            sorted_values.push_back(temp->data);
            temp = temp->next;
        }
        sort(begin(sorted_values), end(sorted_values));
        temp = head;
        for (int i = 0; i < sorted_values.size(); i += 1) {
            temp->data = sorted_values[i];
            temp = temp->next;
        }
        return head;
    }
};