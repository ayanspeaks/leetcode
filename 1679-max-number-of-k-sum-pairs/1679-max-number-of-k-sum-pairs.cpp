class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int count = 0;
        
        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Use two pointers to find pairs
        while (l < r) {
            if (nums[l] + nums[r] == k) {
                count++; // Found a pair
                l++;
                r--;
            } else if (nums[l] + nums[r] < k) {
                l++; // Increment left pointer to increase sum
            } else {
                r--; // Decrement right pointer to decrease sum
            }
        }
        
        return count; // Return the number of pairs found
    }
};
