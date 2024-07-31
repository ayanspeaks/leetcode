class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> out;  // Output vector to store results
        int max = *max_element(candies.begin(), candies.end());  // Find the maximum number of candies any kid has
        
        // Loop through each kid's candies
        for(int i = 0; i < candies.size(); i++) {
            // Check if the current kid's candies plus extraCandies is greater than or equal to the max
            if(candies[i] + extraCandies >= max)
                out.push_back(true);  // This kid can have the maximum candies
            else
                out.push_back(false);  // This kid cannot have the maximum candies
        }
        
        return out;  // Return the result
    }
};
