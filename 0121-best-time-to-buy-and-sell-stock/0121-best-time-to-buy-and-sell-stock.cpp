class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];  // Initialize the minimum price to the first element
        int maxProfit = 0;     // Initialize the maximum profit to 0
        int n = prices.size(); // Get the size of the prices array
        
        // Iterate through each price
        for(int i = 0; i < n; i++) {
            // Calculate the potential profit if selling at the current price
            int cost = prices[i] - mini;
            
            // Update the maximum profit if the current profit is higher
            maxProfit = max(maxProfit, cost);
            
            // Update the minimum price encountered so far
            mini = min(mini, prices[i]);
        }
        
        return maxProfit; // Return the maximum profit
    }
};
