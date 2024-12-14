class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long i = 0;
        multiset<int> s;
        long long ans=0;
        for(auto&x:nums){
            while(s.size() && (x-*s.begin()>2 || *s.rbegin()-x>2)){
                s.erase(s.find(nums[i++]));
            }
            s.insert(x);
            ans += (long long) s.size();
        }
        return ans;
    }
};