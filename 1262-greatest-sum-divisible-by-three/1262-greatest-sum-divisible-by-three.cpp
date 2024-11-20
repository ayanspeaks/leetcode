
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        vector<vector<int>> dp(3);
        int n =nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]%3 == 1)
            dp[0].push_back(nums[i]);
            else if(nums[i]%3 == 2)
            dp[1].push_back(nums[i]);
            else
            dp[2].push_back(nums[i]);
        }

        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum = sum+nums[i];

        int l=dp[0].size(),r=dp[1].size();
        int sum1=0,sum2=0;

        if(sum%3 == 0)
        return sum;
        else if(sum%3 == 1){
            if(l>0)
            sum1 = sum-dp[0][0];
            if(r>=1)
            sum2 = sum-dp[1][0]-dp[1][1];
            return max(sum1,sum2);
        }else{
            if(l>1)
            sum1 = sum-dp[0][0]-dp[0][1];
            if(r>0)
            sum2 = sum-dp[1][0];
            return max(sum1,sum2);
        }

    }
};