class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenation in both orders results in the same string
        // This ensures str1 and str2 have the same repeating pattern
        if (str1 + str2 == str2 + str1) {
            // Find the greatest common divisor (gcd) of the lengths of str1 and str2
            // The substring from 0 to gcd(length of str1, length of str2) will be the result
            return str1.substr(0, gcd(str1.size(), str2.size()));
        }
        // If the concatenations are not equal, there is no common divisor string
        return "";
    }
};
