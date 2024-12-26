class Solution {
public:
    int solve(int idx, int target, vector<int>&nums,vector<vector<int>>&dp){
        //base condition
        if(idx<0)return target==0;
        //check the cache
        if(dp[idx][target]!=-1)return dp[idx][target];
        int notpick=solve(idx-1,target,nums,dp);
        int pick=0;
        if(target>=nums[idx])
            pick=solve(idx-1,target-nums[idx],nums,dp);
        return dp[idx][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums)sum+=it;
        if((sum+target)%2 || (sum-target)<0)return 0;
        target=sum-target;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target/2,nums,dp);
    }
};