class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN; // Initialize MAX to the smallest possible integer value
        int sum = 0;       // Initialize sum to 0
        for(int i = 0; i < nums.size(); i++) { // Iterate through each element in the array
            sum += nums[i]; // Add current element to sum
            MAX = max(sum, MAX); // Update MAX if the current sum is greater than MAX
            if(sum < 0) sum = 0; // Reset sum to 0 if it becomes negative
        }
        return MAX;
    }
};
