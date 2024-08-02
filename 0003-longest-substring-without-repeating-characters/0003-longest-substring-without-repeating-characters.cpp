class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0; // To store the length of the longest substring without repeating characters
        int l = 0, r = 0; // Two pointers for the sliding window
        unordered_map<char, int> chars; // Hash map to store characters and their most recent indices
        
        // Iterate through the string with the right pointer
        while (r < s.length()) {
            auto it = chars.find(s[r]); // Find the current character in the hash map
            
            // If the character is found and its index is within the current window
            if (it != chars.end() && it->second >= l) {
                l = it->second + 1; // Move the left pointer to the right of the previous index of the character
            } else {
                // Update the result if the current window length is greater than the previous result
                result = max(result, r - l + 1);
            }
            
            // Update the hash map with the current character's index
            chars[s[r]] = r;
            r++; // Move the right pointer to the next character
        }
        
        return result; // Return the length of the longest substring without repeating characters
    }
};
