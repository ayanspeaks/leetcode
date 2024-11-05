class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        
        vector<vector<int>> dp(n, vector<int>(2));
        
        dp[0][0]=(s[0]=='0'?0:1);
        dp[0][1]=(s[0]=='1'?0:1);
        
        for(int i=1; i<n; i++){
            
            dp[i][0]=dp[i-1][0]+(s[i]=='0'?0:1);
            dp[i][1]=dp[i-1][1]+(s[i]=='1'?0:1);
            
            if(i%2==0){
                dp[i][0]=min(dp[i][0], dp[i-1][1]+(s[i]=='0'?0:1));
                dp[i][1]=min(dp[i][1], dp[i-1][0]+(s[i]=='1'?0:1));
            } else {
                dp[i][0]=min(dp[i][0], dp[i-1][0]+(s[i]=='0'?0:1));
                dp[i][1]=min(dp[i][1], dp[i-1][1]+(s[i]=='1'?0:1));
            }
        }
        
        return min(dp[n-1][0], dp[n-1][1]);
    }
};