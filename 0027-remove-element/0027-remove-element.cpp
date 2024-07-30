class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;  // Index to place the next non-val element
        
        // Iterate through the elements in the array
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not equal to val, place it at the index position
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;  // Move to the next position
            }
        }
        
        // Return the new length of the array after removal
        return index;
    }
};
