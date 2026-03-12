class Solution {
  public:
    long subarrayXor(vector<int> & nums, int k) {
        // code here
        //count find karna hai, isly i nahi daal rahe bas plus kar rahe
        int n = nums.size();
        unordered_map<int, int>mp;
        mp.insert({0, 1});
        int Xor = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            Xor = Xor ^ nums[i];
            
            if(mp.find(Xor ^ k) != mp.end())
                count += mp[Xor ^ k];
            
            mp[Xor]++;
        }
        return count;
    }
};