class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result array with 1
        
        // Calculate the left products and store them in the result array
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Calculate the right products and multiply them into the result array
        int rightProduct = 1; // Initialize right product as 1
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct; // Multiply with the right product
            rightProduct *= nums[i]; // Update the right product
        }
        
        return result;
    }
};
