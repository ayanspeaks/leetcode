class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum = 0;           // Total sum of all elements
        int curr_sum1 = 0;           // Current sum for max subarray calculation
        int curr_sum2 = 0;           // Current sum for min subarray calculation
        int mxsum_subary = INT_MIN;  // Max sum subarray found so far
        int minsum_subary = INT_MAX; // Min sum subarray found so far

        // Iterate through each element in the array
        for (auto i : A) {
            total_sum += i;         // Update total sum
            curr_sum1 += i;         // Update current sum for max subarray
            curr_sum2 += i;         // Update current sum for min subarray

            // Update max subarray sum
            mxsum_subary = max(mxsum_subary, curr_sum1);
            if (curr_sum1 < 0) curr_sum1 = 0; // Reset if current sum becomes negative

            // Update min subarray sum
            minsum_subary = min(curr_sum2, minsum_subary);
            if (curr_sum2 > 0) curr_sum2 = 0; // Reset if current sum becomes positive
        }

        // Return the maximum of the normal max subarray or the max circular subarray
        return (total_sum == minsum_subary) ? mxsum_subary : max(mxsum_subary, total_sum - minsum_subary);
    }
};
