class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int whiteCount = 0;  // Count of white balls on the left
        long long steps = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                // If the ball is white, increment the count of white balls on the left
                whiteCount++;
            } else {
                // If the ball is black, add the current white count to the steps
                steps += whiteCount;
            }
        }

        // The final result is the minimum number of steps required
        return steps;
    }
};