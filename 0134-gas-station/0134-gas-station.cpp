class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalDiff = 0;  // Total difference between gas and cost
        int fuel = 0;       // Current fuel balance
        int index = 0;      // Starting index
        int n = gas.size(); // Number of gas stations
        
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];  // Difference at current station
            totalDiff += diff;            // Update total difference
            fuel += diff;                 // Update current fuel balance
            
            if (fuel < 0) {
                // If fuel balance is negative, reset starting index to next station
                index = i + 1;
                fuel = 0; // Reset current fuel balance
            }
        }
        
        // If total difference is negative, it's impossible to complete the circuit
        return (totalDiff < 0) ? -1 : index;
    }
};
