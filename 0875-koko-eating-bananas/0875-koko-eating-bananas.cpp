class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize the starting speed to 1 banana per hour
        int start = 1;
        // Find the maximum pile size to set the upper bound for speed
        int end = *max_element(piles.begin(), piles.end());

        // Perform binary search to find the minimum eating speed
        while (start < end) {
            // Calculate the midpoint speed
            int mid = start + (end - start) / 2;
            // Initialize total hours needed to 0
            int totalHours = 0;

            // Calculate total hours needed to eat all piles at the current speed
            for (int pile : piles) {
                // Calculate hours needed for the current pile at mid speed
                totalHours += (pile + mid - 1) / mid; // Equivalent to ceil(pile / mid)
            }

            // If total hours exceeds the available hours, increase speed
            if (totalHours > h) {
                start = mid + 1; // Increase the eating speed
            } else {
                // If within the limit, try for a lower speed
                end = mid; // Set end to mid to check for a smaller speed
            }
        }

        // When start meets end, return the minimum speed found
        return start;
    }
};
