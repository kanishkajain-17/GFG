// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.size();
        stack<string>st;
        
        for(int i = 0; i < n; i++){
            if(isalpha(post_exp[i]) || isdigit(post_exp[i]))
                st.push(string(1, post_exp[i]));
            else{
                string temp = "";
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                temp = s1 + s2 + post_exp[i];
                st.push(temp);
            }
        }
        string ans = st.top();
        reverse(begin(ans), end(ans));
        return ans;
    }
};