class Solution {
  public:
    void insert(int x, stack<int>&st){
        if(st.empty())
            st.push(x);
        else{
           
                int temp = st.top();
                st.pop();
                insert(x, st);
                st.push(temp);
            
        }
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size() > 0){
            int x = st.top();
            st.pop();
            reverseStack(st);
            insert(x, st);
        }
    }
};