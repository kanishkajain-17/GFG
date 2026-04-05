class Solution {
  public:
    void insert(int x, stack<int>& st){
        if(st.empty()){
            st.push(x);
        }
        else{
            if(st.top() > x){
                int temp = st.top();
                st.pop();
                insert(x, st);
                st.push(temp);
            }
            else //if(st.top() < x)
                st.push(x);
        }
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.size() > 0){
            int x = st.top();
            st.pop();
            sortStack(st);
            insert(x, st);
        }
    }
};
