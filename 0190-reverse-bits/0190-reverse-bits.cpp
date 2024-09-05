class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;  // Initialize result to 0

        // Loop over all 32 bits of the input number
        for (int i = 31, j = 0; i >= 0; i--, j++) {
            // Check if the ith bit in n is set
            if ((n & (1 << i)) != 0) {
                // If set, set the jth bit in rev
                rev |= (1 << j); // Update rev by setting the jth bit
            }
        }

        return rev;  // Return the reversed bit representation
    }
};
