class Solution {
public:
    int singleNumber(vector<int>& nums) {
        uint32_t arr[32] = {0};

        for (int x : nums) {
            for (int ii = 0; ii < 32; ++ii) {
                arr[ii] += x&1;
                x >>= 1;
            }
        }

        int res = 0;
        for (int ii = 31; ii >= 0; --ii) {
            res <<= 1;
            if (arr[ii] % 3 != 0) {
                res |= 1;
            }
        }

        return res;
    }
};