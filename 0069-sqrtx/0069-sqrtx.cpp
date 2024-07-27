class Solution {
public:
    int mySqrt(int x) {
        // Handle the edge case where x is 0
        if (x == 0)
            return 0;

        // Initialize the binary search range
        int first = 1, last = x;

        // Perform binary search
        while (first <= last) {
            int mid = first + (last - first) / 2;

            // Check if mid is the integer square root of x
            if (mid == x / mid)
                return mid;
            // If mid*mid is greater than x, search in the lower half
            else if (mid > x / mid) {
                last = mid - 1;
            }
            // If mid*mid is less than x, search in the upper half
            else {
                first = mid + 1;
            }
        }

        // Return the last valid value of last, which is the integer part of the square root
        return last;
    }
};
