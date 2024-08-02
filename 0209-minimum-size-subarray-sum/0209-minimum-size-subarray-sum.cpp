class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int total = 0; // To store the sum of the current subarray
        int start = 0; // Left boundary of the sliding window
        int minLength = 1e5 + 1; // Initialize with a large value
        
        // Traverse the array with the right boundary of the sliding window
        for (int end = 0; end < n; end++) {
            total += nums[end]; // Add the current element to the total sum
            
            // Shrink the window from the left as long as the total is greater than or equal to the target
            while (total >= target) {
                // Update the minimum length of the subarray
                minLength = min(minLength, end + 1 - start);
                total -= nums[start++]; // Remove the leftmost element and move the left boundary
            }
        }
        
        // If minLength was not updated, return 0, else return minLength
        return (minLength == 1e5 + 1 ? 0 : minLength);
    }
};
