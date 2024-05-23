class Solution {
public:
  
  int exe(int n , vector<int> &dp){
if(n==0 || n==1)
return 1;

if(dp[n]!=-1)
return dp[n];

int ans=0;
for(int i=1; i<=n; i++){
    ans+=exe(i-1,dp)*exe(n-i,dp);
}
return dp[n]=ans;
  }

 int numTrees(int n) {
    vector<int>dp(n+1,-1);
    return exe(n,dp);
    }
};