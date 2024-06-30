class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        if (target > nums[high]) {
            return high + 1;
        }

        while (low <= high) {
            mid = low + (high - low) / 2; // Avoids overflow

            if (nums[mid] == target) {
                return mid;
            }

            if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};