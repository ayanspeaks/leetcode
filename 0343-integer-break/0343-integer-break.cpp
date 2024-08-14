class Solution {
public:
    int dp[59], x;
    int helper(int n){
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int product = 1;
        for(int i = 1 ; i <= n ; i++){
            if(i != x)
                product = max(product, i * helper(n - i));
        }
        return dp[n] = product;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        x = n;
        return helper(n);
    }
};