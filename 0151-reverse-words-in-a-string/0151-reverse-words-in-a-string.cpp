class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string first
        reverse(s.begin(), s.end());
        
        int l = 0, r = 0, i = 0, n = s.size();

        while (i < n) {
            // Move `r` and `i` to the end of the current word
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { 
                // If we have found a non-empty word
                // Reverse the current word
                reverse(s.begin() + l, s.begin() + r);

                if (r == n) break; // If we've reached the end, break out

                s[r++] = ' '; // Set a space after the word
                l = r; // Move `l` to the start of the next word
            }
            ++i; // Skip the space
        }

        if (r > 0 && s[r-1] == ' ') --r; // Remove trailing space if present

        s.resize(r); // Resize the string to remove any extra spaces at the end

        return s; // Return the result
    }
};

