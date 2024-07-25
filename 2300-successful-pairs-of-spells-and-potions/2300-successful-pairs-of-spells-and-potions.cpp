class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        int m = potions.size();
        
        // Sort the potions array for binary search
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < spells.size(); ++i) {
            long long required = (success + spells[i] - 1) / spells[i]; // Minimum value of potion needed
            // Binary search for the first potion that meets the requirement
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (potions[mid] < required) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            // Count how many potions are >= required
            ans[i] = m - low;
        }
        
        return ans;
    }
};
