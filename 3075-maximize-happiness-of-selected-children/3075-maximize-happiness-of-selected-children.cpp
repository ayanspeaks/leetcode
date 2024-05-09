class Solution {
public:
    long long maximumHappinessSum(vector<int>& hs, int k) {
        sort(hs.begin(), hs.end(), greater<int>());
        long long sum = 0;
        for (auto i = 0; i < k; i++) sum += max(0, hs[i] - i);
        return sum;
    }
};