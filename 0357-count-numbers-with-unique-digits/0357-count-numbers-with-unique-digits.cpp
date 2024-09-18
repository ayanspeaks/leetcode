class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[10];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = 9;
        dp[2] = 9*9;
        dp[3] = 9*9*8;
        dp[4] = 9*9*8*7;
        dp[5] = 9*9*8*7*6;
        dp[6] = 9*9*8*7*6*5;
        dp[7] = 9*9*8*7*6*5*4;
        dp[8] = 9*9*8*7*6*5*4*3;
        int ans = 0;
        for(int i=0;i<=n;i++)
            ans += dp[i];
        return ans;
    }
};