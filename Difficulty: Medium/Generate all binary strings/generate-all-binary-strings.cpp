class Solution {
  public:
    vector<string>ans;
    void solve(string temp, int n){
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }   
        solve(temp + '0', n);
        solve(temp + '1', n);
        
    }
    vector<string> binstr(int n) {
        // code here
         solve("", n);
         return ans;
    }
};