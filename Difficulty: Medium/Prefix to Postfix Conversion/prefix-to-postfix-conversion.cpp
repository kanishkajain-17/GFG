// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        
        int n = pre_exp.size();
        stack<string>st;
        
        for(int i = n - 1; i >= 0; i--){
            if(isalpha(pre_exp[i]) || isdigit(pre_exp[i]))
                st.push(string(1, pre_exp[i]));
            else{
                string temp = ""; 
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                temp = s1 + s2 + pre_exp[i];
                st.push(temp);
            }
        }
        return st.top();
    }
};