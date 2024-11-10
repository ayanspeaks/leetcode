class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //xor atleast k 
        int ans = nums.size() + 1; 
        int _or = 0; 
        
        vector<int> bitCount(32, 0); //to store how many bit at ith position in the window is set 
        int left = 0; 
        for(int i = 0; i < nums.size(); i++) {
            _or |= nums[i]; 
            
            //set the bits in bitCount for nums[i]
            for(int j = 31; j >= 0; j--) {
                // bit set n & (1 << k)
                bitCount[j] += (nums[i] & (1 <<j)) > 0; 
            }
            
            // if _or greater than k 
            while(left <= i && _or >= k) {
                if(_or >= k) ans = min(ans, i - left + 1); //update answer 
                int new_or = 0; 
                for(int j = 31; j >= 0; j--) {
                    int bit = nums[left] & (1 << j); 
                    // cout<<bit<<endl; 
                    bitCount[j] -= bit > 0;  
                    if(bitCount[j] > 0) new_or |= (1 << j); //if bitCount[j] > 0 , ith bit still set, set the bit in new_or 
                }
                
                _or = new_or; 
                left++; 
            }
            
        }
        
        return ans == nums.size() + 1 ? -1 : ans; 
    }
};