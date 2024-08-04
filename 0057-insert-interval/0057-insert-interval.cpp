class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        // Iterate through each interval in the list
        for(auto currentInterval : intervals) {
            // Case 1: Non-overlapping (current interval ends before new interval starts)
            if(currentInterval[1] < newInterval[0]) {
                ans.push_back(currentInterval); // Add current interval to the result
            }
            // Case 1: Non-overlapping (new interval ends before current interval starts)
            else if(newInterval[1] < currentInterval[0]) {
                ans.push_back(newInterval); // Add new interval to the result
                newInterval = currentInterval; // Update newInterval to current interval for further checking
            }
            // Case 2: Overlapping intervals
            else {
                // Merge intervals by updating the start and end of newInterval
                newInterval[0] = min(currentInterval[0], newInterval[0]);
                newInterval[1] = max(currentInterval[1], newInterval[1]);
            }
        }
        // Add the last interval (newInterval)
        ans.push_back(newInterval);

        return ans; // Return the result
    }
};
