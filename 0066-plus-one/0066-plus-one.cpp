class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size(); // Get the size of the vector
        // Traverse from the last digit to the first digit
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) // Increment the last digit
                v[i]++; // Add one to the last digit
            if (v[i] == 10) { // Handle carry if the digit becomes 10
                v[i] = 0; // Set the current digit to 0 (because 10 means carry)
                if (i != 0) {
                    v[i - 1]++; // Carry over to the next significant digit
                } else { // When the most significant digit also needs a carry
                    v.push_back(0); // Add an extra space at the end
                    v[i] = 1; // Set the most significant digit to 1
                }
            }
        }
        return v; // Return the modified vector
    }
};
