class Solution {
public:
    string compressedString(string word) {
         string comp = "";
        int n = word.length();
        int i = 0;
        
        while (i < n) {
            char c = word[i];
            int length = 0;
            
            // Find the length of the prefix of repeating character `c` (up to 9 characters)
            while (i < n && word[i] == c && length < 9) {
                ++i;
                ++length;
            }
            
            // Append length and character to the compressed string
            comp += to_string(length) + c;
        }
        
        return comp;
    }
};