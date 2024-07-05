class Solution {
public:
    bool isPalindrome(int x) {
        // Early return for negative numbers and numbers ending with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        long long rev = 0;
        int ori = x;
        while (x > 0) {
            int r = x % 10;
            x = x / 10;
            rev = rev * 10 + r;
        }
        return rev == ori;
    }
};