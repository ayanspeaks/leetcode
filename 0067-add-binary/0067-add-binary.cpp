class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0; // Initialize carry for addition
        stringstream result; // Using stringstream for efficient string building
        int i = a.size() - 1, j = b.size() - 1; // Initialize pointers to the end of both strings

        // Loop through both strings from end to start, adding corresponding digits
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with the current carry
            
            // Add the digit from string a if available
            if (i >= 0) {
                sum += a[i--] - '0'; // Convert char to int and decrement index
            }
            // Add the digit from string b if available
            if (j >= 0) {
                sum += b[j--] - '0'; // Convert char to int and decrement index
            }
            
            // Append the binary digit (0 or 1) to the result
            result << (sum % 2); // sum % 2 gives the binary digit
            carry = sum / 2; // Compute the carry for the next digit
        }

        // Convert the stringstream to a string and reverse it to get the final result
        string res = result.str(); // Get the result as a string
        reverse(res.begin(), res.end()); // Reverse the string since we built it backwards
        return res; // Return the final binary sum
    }
};
