class Solution {
public:
    int solve(int target,vector<int> &nums,vector<int> &dp){
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=solve(target-nums[i],nums,dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(target,nums,dp);
    }
};