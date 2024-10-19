class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        const int mid = pow(2, n-1);
        if(k == mid) return '1';
        if(k<mid) return findKthBit(n-1, k);
        return findKthBit(n - 1, mid * 2 - k) == '0' ? '1' : '0';
    }
};