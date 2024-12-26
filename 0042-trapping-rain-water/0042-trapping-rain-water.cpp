class Solution {
public:
    int trap(vector<int>& height) {
        // Get the size of the height array
        int n = height.size();
        
        // If the array is empty, return 0 as no water can be trapped
        if (n == 0) return 0;

        // Initialize two pointers: left starts from the beginning, right starts from the end
        int left = 0, right = n - 1;
        // Initialize variables to track the maximum heights encountered so far from the left and right
        int left_max = 0, right_max = 0;
        // Variable to store the total water trapped
        int sum = 0;

        // Traverse the array using the two pointers
        while (left < right) {
            // Process the side with the lower height
            if (height[left] < height[right]) {
                // If current height at left is greater than or equal to left_max, update left_max
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    // Otherwise, add the water trapped at this position to the sum
                    sum += left_max - height[left];
                }
                // Move the left pointer to the right
                left++;
            } else {
                // If current height at right is greater than or equal to right_max, update right_max
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    // Otherwise, add the water trapped at this position to the sum
                    sum += right_max - height[right];
                }
                // Move the right pointer to the left
                right--;
            }
        }

        // Return the total amount of water trapped
        return sum;
    }
};
