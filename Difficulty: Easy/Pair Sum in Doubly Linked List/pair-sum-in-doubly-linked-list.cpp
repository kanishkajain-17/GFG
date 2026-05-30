// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        unordered_set<int> st;
        Node* temp = head;
        vector<pair<int, int>> ans;
        while (temp != NULL) {
            int val = temp->data;
            if(st.find(target - val) != st.end()) {
                ans.push_back({target - val, val});
            }
            else
                st.insert(val);
            temp = temp->next;
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};