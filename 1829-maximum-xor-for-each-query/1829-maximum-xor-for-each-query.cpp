class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> v;
        int no=pow(2,maximumBit)-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
            
            v.push_back(ans^no);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};