class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // Populate the dp table with the given prices
        for (auto& price : prices) {
            int hi = price[0], wi = price[1];
            dp[hi][wi] = max(dp[hi][wi], static_cast<long long>(price[2]));
        }
        
        // DP to calculate maximum profit for every size i x j
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Check all possible horizontal cuts
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                // Check all possible vertical cuts
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
        
        return dp[m][n];
    }
};
