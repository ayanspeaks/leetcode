class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // If the haystack is shorter than the needle, needle can't be found
        if(haystack.size() < needle.size()) {
            return -1;
        }
        
        int j = 0; // Index for needle
        // Loop through the haystack up to the point where the remaining characters are less than the length of the needle
        for(int i = 0; i <= haystack.size() - needle.size(); i++) {
            // Check if the current character matches the first character of the needle
            if(haystack[i] == needle[j]) {
                int l = i; // Index for haystack
                // Check the subsequent characters
                while(j < needle.size() && haystack[l] == needle[j]) {
                    l++;
                    j++;
                }
                // If we've checked all characters in the needle, return the start index
                if(j == needle.size()) {
                    return i;
                }
            }
            // Reset needle index if full match not found
            j = 0;
        }
        // Return -1 if needle not found in haystack
        return -1;
    }
};
