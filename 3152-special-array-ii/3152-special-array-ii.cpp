class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixMismatch(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixMismatch[i] = prefixMismatch[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefixMismatch[i]++;
            }
        }
        vector<bool> res;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == end) {
                res.push_back(true);
                continue;
            }
            int mismatches = prefixMismatch[end] - prefixMismatch[start];
            res.push_back(mismatches == 0);
        }
        return res;
    }
};