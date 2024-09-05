class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumM = accumulate(rolls.begin(), rolls.end(), 0);
        int sumN = mean * (m+n) - sumM;

        if(sumN < n || sumN > 6*n) return {};

        int div = sumN / n;
        int rem = sumN % n;
        vector<int> ans(n, div);
        for(int i=0; i<rem; i++){
            ans[i] += 1;
        }

        return ans;
    }
};