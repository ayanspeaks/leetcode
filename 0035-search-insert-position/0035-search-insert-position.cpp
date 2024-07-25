#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        // If target is greater than the last element, it should be inserted at the end
        if (target > nums[high]) {
            return high + 1;
        }

        // Binary search
        while (low <= high) {
            mid = low + (high - low) / 2; // Calculate mid to avoid overflow

            if (nums[mid] == target) {
                return mid; // Target found
            }

            if (target < nums[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        }

        // Return the insert position
        return low;
    }
};

