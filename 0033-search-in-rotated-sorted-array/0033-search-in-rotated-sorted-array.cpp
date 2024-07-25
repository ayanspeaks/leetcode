#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();  // Size of the array
        int low = 0;          // Start of the search range
        int high = n - 1;     // End of the search range

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate mid

            // If mid points to the target
            if (nums[mid] == target) return mid;

            // If the left part is sorted
            if (nums[low] <= nums[mid]) {
                // Check if the target is within the left part
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1; // Search in the left part
                } else {
                    low = mid + 1; // Search in the right part
                }
            } else { // If the right part is sorted
                // Check if the target is within the right part
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1; // Search in the right part
                } else {
                    high = mid - 1; // Search in the left part
                }
            }
        }

        // Target not found
        return -1;
    }
};
