bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1]; // Comparator to sort intervals based on their end points
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0; // If there are no intervals, return 0
        
        // Sort the points based on their end points
        sort(points.begin(), points.end(), comp);
        
        int arrows = 1; // Start with one arrow
        int end = points[0][1]; // End point of the first interval
        
        for(int i = 1; i < points.size(); i++) {
            // If the start of the current interval is greater than the end of the last interval
            if(points[i][0] > end) {
                arrows++; // We need a new arrow
                end = points[i][1]; // Update the end to the end of the current interval
            }
        }
        return arrows; // Return the minimum number of arrows needed
    }
};
