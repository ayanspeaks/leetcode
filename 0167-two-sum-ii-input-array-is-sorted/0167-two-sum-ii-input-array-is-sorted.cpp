class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;  // Initialize left pointer
        int j = numbers.size() - 1;  // Initialize right pointer

        while (i < j) {
            // Check if the sum of elements at i and j equals the target
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};  // Return 1-based indices if target is found

            // If the sum is less than the target, move the left pointer to the right
            if (numbers[i] + numbers[j] < target)
                i++;
            // If the sum is greater than the target, move the right pointer to the left
            else
                j--;
        }

        return {};  // Return empty vector if no solution is found
    }
};
