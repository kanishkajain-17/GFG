class Solution {
  public:
    vector<string> ans;
    void solve(int n, int i, string temp) {
        
        if(i == n) {
            ans.push_back(temp);
            return;
        }
        
        solve(n, i + 1, temp + '0');
        solve(n, i + 1, temp + '1');
        
    } 
    vector<string> binstr(int n) {
        // code here
        string temp = "";
        solve(n, 0, temp);
        return ans;
    }
};