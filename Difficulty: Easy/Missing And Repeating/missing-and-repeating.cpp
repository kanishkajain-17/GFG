class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        long long matsum = 0;
        long long matsqSum = 0;

        for(int i = 0; i < n; i++){
            matsum += arr[i];
            matsqSum += 1LL * arr[i] * arr[i];
        }

        long long sum = (1LL * n * (n + 1)) / 2;
        long long sqSum = (1LL * n * (n + 1) * (2*n + 1)) / 6;

        long long sqDiff = matsqSum - sqSum;
        long long sumDiff = matsum - sum;

        long long a = (sqDiff / sumDiff + sumDiff) / 2; // repeating
        long long b = (sqDiff / sumDiff - sumDiff) / 2; // missing

        return {(int)a, (int)b};
    }
};