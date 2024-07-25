#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int low = 0, high = nums.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    high = mid - 1; // Continue searching in the left half
                } else {
                    low = mid + 1; // Continue searching in the right half
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};
