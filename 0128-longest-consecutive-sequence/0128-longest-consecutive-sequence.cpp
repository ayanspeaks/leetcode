class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a set to store unique numbers from the input array
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int ans = 0; // Variable to store the maximum length of consecutive numbers

        // Iterate through the numbers in the array
        for (int i = 0; i < nums.size(); i++) {
            // If the previous number (current - 1) exists in the set, skip to the next number
            if (s.find(nums[i] - 1) != s.end()) {
                continue;
            } else {
                // Start counting consecutive numbers from the current number
                int count = 0;
                int current = nums[i];

                // Count how many consecutive numbers exist starting from the current number
                while (s.find(current) != s.end()) {
                    count++;
                    current++;
                }
                
                // Update the maximum length found
                ans = max(ans, count);
            } 
        }
        return ans; // Return the maximum length of consecutive numbers
    }
};
