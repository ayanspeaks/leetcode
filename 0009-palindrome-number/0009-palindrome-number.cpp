class Solution {
public:
    bool isPalindrome(int x) {
        // Early return for negative numbers and numbers ending with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        long long rev = 0; // Variable to store the reversed number
        int ori = x; // Store the original number for comparison
        
        while (x > 0) {
            int r = x % 10; // Get the last digit of x
            x = x / 10; // Remove the last digit from x
            rev = rev * 10 + r; // Append the digit to the reversed number
        }
        
        // Check if the reversed number is equal to the original number
        return rev == ori;
    }
};
