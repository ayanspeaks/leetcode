class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reduce k to the smallest equivalent rotation
        k %= nums.size();
        
        // Reverse the first part of the array
        reverse(nums.begin(), nums.end() - k);
        
        // Reverse the second part of the array
        reverse(nums.end() - k, nums.end());
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
    }
};
