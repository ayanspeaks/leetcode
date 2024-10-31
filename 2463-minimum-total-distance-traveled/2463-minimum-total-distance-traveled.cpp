class Solution {
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        int n = r.size();
        int m = f.size();
        
        sort(r.begin() , r.end());
        sort(f.begin() , f.end());
        
        long long int dp[n + 1][m + 1];
        for(int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 1e17;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i][j - 1];
                long long int cur = 0;
                int sz = max(1 , i - f[j - 1][1] + 1);
                for(int k = i; k >= sz; k--)
                {
                    cur += abs(r[k - 1] - f[j - 1][0]);
                    dp[i][j] = min(dp[k - 1][j - 1] + cur , dp[i][j]);
                }    
            }
        }

        return dp[n][m];
    }
};