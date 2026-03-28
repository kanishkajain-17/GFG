class Solution {
  public:
    int isPre(char ch){
        switch(ch){
            case '^' : return 3;
            case '*' : 
            case '/' : return 2;
            case '+' : 
            case '-' : return 1;
            
        }
        return 0;
    }
    
    string infixToPostfix(string& s) {
        // code here
        int n = s.length();
        stack<char>st;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(s[i]);
                
            else if(s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= 'A' && s[i] <= 'Z' ||
                s[i] >= '0' && s[i] <= '9')
                    ans += s[i];
                    
            else if(s[i] == ')'){
                while(st.top() != '('){
                    char ch = st.top();
                    ans += ch;
                    st.pop();
                }
                
                st.pop();
            }
            
            else{
                while(!st.empty() && st.top() != '(' &&
                ((s[i] != '^' &&  isPre(s[i]) <= isPre(st.top())) ||
                (s[i] == '^' &&  isPre(s[i]) < isPre(st.top())))){
                    char ch = st.top();
                    ans += ch;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
