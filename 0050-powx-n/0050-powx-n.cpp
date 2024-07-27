class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the edge case when n is INT_MIN
        long long N = n;

        // If the exponent is negative, invert the base and make the exponent positive
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        // Exponentiation by squaring
        while (N) {
            // If the current exponent is odd, multiply the result by the current base
            if (N % 2 == 1) {
                result *= x;
            }
            // Square the base
            x *= x;
            // Halve the exponent
            N /= 2;
        }

        return result;
    }
};
