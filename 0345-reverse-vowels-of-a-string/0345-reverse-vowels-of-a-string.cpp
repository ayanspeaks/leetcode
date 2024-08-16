class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        if (n == 1) // If the string has only one character, return it as is
            return s;

        vector<bool> vis(n, false); // Boolean vector to mark positions of vowels
        string vow = ""; // String to store all vowels in the original string

        // Identify all vowels and store them in 'vow' while marking their positions in 'vis'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I' || 
                s[i] == 'e' || s[i] == 'E' || s[i] == 'o' || s[i] == 'O' || 
                s[i] == 'u' || s[i] == 'U') {
                vis[i] = true;
                vow += s[i];
            }
        }

        // Reverse the string containing all vowels
        reverse(vow.begin(), vow.end());

        int j = 0; // Index for the reversed vowels string
        // Replace the vowels in the original string with the reversed vowels
        for (int i = 0; i < n; i++) {
            if (vis[i] == true) {
                s[i] = vow[j];
                j++;
            }
        }

        return s; // Return the modified string
    }
};
