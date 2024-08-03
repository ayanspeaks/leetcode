class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths of the strings are not equal, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Create a map to count the occurrences of each character
        unordered_map<char, int> charCount;

        // Count the characters in the first string
        for (char c : s) {
            charCount[c]++;
        }
        // Decrease the count for the characters in the second string
        for (char c : t) {
            charCount[c]--;
            // If the count goes negative, it means t has more of this character than s
            if (charCount[c] < 0) {
                return false;
            }
        }

        // If we get here, all counts should be zero
        return true;
    }
};
