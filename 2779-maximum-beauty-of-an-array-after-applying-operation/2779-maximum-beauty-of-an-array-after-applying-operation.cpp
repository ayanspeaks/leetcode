class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto it:nums){
            m[it-k]++;
            m[it+k+1]--;
        }
        int sum=0,maxi=0;
        for(auto it:m){
            sum+=it.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};