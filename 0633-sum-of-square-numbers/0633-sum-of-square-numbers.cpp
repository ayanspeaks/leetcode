class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;

        for (long long i = 0; i * i <= c; i++) {
            long long cc = c - i * i;
            long long cc_sqrt = sqrt(cc);
            if (cc_sqrt * cc_sqrt == cc) {
                return true;
            }
        }

        return false;
    }
};