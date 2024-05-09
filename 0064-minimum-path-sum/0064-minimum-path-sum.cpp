class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
         dp[i][1] =g[i-1][0] + dp[i-1][1];
        }
        for(int j=1;j<=m;j++){
         dp[1][j] = g[0][j-1] + dp[1][j-1];   
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                dp[i][j] = g[i-1][j-1] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};