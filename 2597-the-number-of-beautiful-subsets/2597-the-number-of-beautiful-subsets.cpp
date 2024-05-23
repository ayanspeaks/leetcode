class Solution {
public:
    void solve(int s,vector<int> &nums,int &k,unordered_map<int,int> &mp,int &ans){
        if(s==nums.size()){ans++;return;}
        if(mp[nums[s]+k]==0&&mp[nums[s]-k]==0){
            mp[nums[s]]++;
            solve(s+1,nums,k,mp,ans);
            mp[nums[s]]--;
        }
        solve(s+1,nums,k,mp,ans);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        solve(0,nums,k,mp,ans);
        return ans-1;
    }
};