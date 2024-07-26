class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0); // Initialize a vector of size n+1 with all zeros
        
        for (int i = 1; i <= n; ++i) {
            // ans[i >> 1] gives the number of 1-bits in i/2
            // (i & 1) checks if the least significant bit of i is 1
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans; // Return the result vector
    }
};
