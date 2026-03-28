// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.size();
        stack<string>st;
        string temp = "";
        
        for(int i = n - 1; i >= 0; i--){
            if(isalpha(pre_exp[i]) || isdigit(pre_exp[i]))
                st.push(string(1, pre_exp[i]));
            
            else{
                temp = "";
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                temp = "(" + s1 + pre_exp[i] + s2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};