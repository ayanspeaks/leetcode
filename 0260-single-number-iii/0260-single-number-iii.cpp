class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto i : nums) xr ^= i;
        int ctz=__builtin_ctz(xr);
        int x1=0, x2=0;
        for(auto i : nums){
            if(i>>ctz & 1) x1^=i;
            else x2^=i; 
        }    
        return vector<int>{x1, x2};
    }
};