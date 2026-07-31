class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        if((n >> k) & (1))
            return true;
        return false;
    }
};