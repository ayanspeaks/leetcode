class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort the citations in ascending order
        sort(citations.begin(), citations.end());
        int n = citations.size(); // Number of papers
        int i;

        // Iterate to find the maximum H-index
        for(i = 1; i <= n; ++i) {
            // Check if the (n-i)th citation is less than i
            if(citations[n - i] < i) {
                break; // If true, we've found the H-index
            }
        }
        
        return i - 1; // Return the maximum H-index
    }
};
