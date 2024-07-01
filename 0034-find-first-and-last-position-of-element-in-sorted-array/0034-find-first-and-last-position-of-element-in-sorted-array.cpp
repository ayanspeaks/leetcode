class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int firstPos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                firstPos = mid;
                high = mid - 1;  // Keep searching in the left half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return firstPos;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int lastPos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                lastPos = mid;
                low = mid + 1;  // Keep searching in the right half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lastPos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = findFirst(nums, target);
        int endingPosition = findLast(nums, target);
        return {startingPosition, endingPosition};
    }
};