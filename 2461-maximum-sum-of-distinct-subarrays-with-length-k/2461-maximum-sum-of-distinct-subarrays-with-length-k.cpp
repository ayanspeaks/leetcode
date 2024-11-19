class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        map<int,int> s;
        long long mx=0;
        long long sm=0;
        while(j<n){
            sm+=nums[j];
            s[nums[j]]++;
            if(j-i+1==k){
                if(s.size()==k){
                    mx=max(mx,sm);
                }
                sm-=nums[i];
                s[nums[i]]--;
                if(s[nums[i]]==0)
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return mx;
    }
};