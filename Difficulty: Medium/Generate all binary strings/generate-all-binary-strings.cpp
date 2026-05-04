class Solution {
  public:
    vector<string>ans;
    void solve(int n, string temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        solve(n, temp + '0');
        solve(n, temp + '1');
    }
    vector<string> binstr(int n) {
        // code here
        string temp = "";
        solve(n, temp);
        return ans;
    }
};