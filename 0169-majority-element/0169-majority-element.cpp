class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: The middle element in a sorted array is guaranteed to be the majority element
        // because the majority element appears more than n/2 times.
        int n = nums.size();
        return nums[n / 2];
    }
};
