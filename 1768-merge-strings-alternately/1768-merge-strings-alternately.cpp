class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(); // Length of word1
        int m = word2.size(); // Length of word2
        string ans = ""; // Result string

        // Merge characters alternately from both strings
        for (int i = 0; i < n && i < m; ++i) {
            ans += word1[i]; // Append character from word1
            ans += word2[i]; // Append character from word2
        }

        // If word1 is longer, append the remaining characters
        if (n > m) {
            ans += word1.substr(m);
        }
        // If word2 is longer, append the remaining characters
        else if (n < m) {
            ans += word2.substr(n);
        }

        return ans; // Return the merged string
    }
};
