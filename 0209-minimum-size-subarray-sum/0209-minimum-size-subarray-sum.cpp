class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int total=0;
        int last=0;
        int mini=1e5+1;
        for(int i=0; i<n; i++){
            total+=nums[i];
            while(total>=target){
                mini=min(mini,i+1-last);
                total-=nums[last++];
            }
        }
        return(mini==1e5+1?0 : mini);
    }
};