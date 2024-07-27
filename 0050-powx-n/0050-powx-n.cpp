class Solution {
public:
    double myPow(double x, int n) {
        // If n is negative, convert x to 1/x and use the absolute value of n
        if(n < 0) {
            x = 1 / x;
        }
        
        // Use long to handle the edge case of INT_MIN
        long num = labs(n);
        double pow = 1;  
        
        // Loop until num becomes zero
        while(num) { // equivalent to while(num != 0)
            // If the current exponent is odd, multiply the result by x
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            // Square the base
            x *= x;
            // Right shift the exponent by 1
            num >>= 1;
        }
        
        // Return the final result
        return pow;
    }
};
