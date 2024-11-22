class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[1].size();
        map<string, int> mp;
        for (auto i : matrix) {
            string res = "";
            for (auto j : i) {
                res += to_string(j);
            }
            if(res[0]!='0'){
                for (int k = 0; k < res.size(); k++) {
                    if (res[k] == '0') {
                        res[k] = '1';
                    } else {
                        res[k] = '0';
                    }
                }
            }
            if (mp.count(res)) {
                mp[res]++;
            } else {
                mp[res]++;
            }
        }
        int ans = 0;
        for (auto [x, y] : mp) {
            ans = max(ans, y);
        }
        return ans;
    }
};