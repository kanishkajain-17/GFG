// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        int n = exp.size();
        stack<string>st;
        
        for(int i = 0; i < n; i++){
            if(isalpha(exp[i]) || isdigit(exp[i]))
                st.push(string(1, exp[i]));
            else{
                string temp = "";
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                temp = "(" + s2 + exp[i] + s1 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};