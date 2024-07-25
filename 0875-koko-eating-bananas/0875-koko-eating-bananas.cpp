class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while (start < end) {
            int mid = start + (end - start) / 2;
            int totalHours = 0;

            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; // equivalent to ceil((double)pile / mid)
            }

            if (totalHours > h) {
                start = mid + 1; // Need more speed
            } else {
                end = mid; // Found a valid speed, try for lower speed
            }
        }

        return start;
    }
};
