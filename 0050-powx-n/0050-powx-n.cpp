class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the edge case when n is INT_MIN
        long long N = n; // Store n in a long long variable to handle cases where n is INT_MIN

        // If the exponent is negative, invert the base and make the exponent positive
        if (N < 0) {
            x = 1 / x; // Invert the base for negative exponent
            N = -N;    // Make the exponent positive
        }

        double result = 1.0; // Initialize result to 1.0, the multiplicative identity

        // Exponentiation by squaring
        while (N) {
            // If the current exponent is odd, multiply the result by the current base
            if (N % 2 == 1) {
                result *= x; // Multiply result by base if exponent is odd
            }
            // Square the base
            x *= x; // Square the base for the next iteration
            // Halve the exponent
            N /= 2; // Reduce the exponent by half
        }

        return result; // Return the final result
    }
};
