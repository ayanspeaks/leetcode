class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), ans = 0, cur = 0;
        unordered_map<char, int> m;
        m['a']++, m['e']++, m['i']++, m['o']++, m['u']++;  // Initialize the map with vowels
        
        for (int i = 0; i < n; i++) {
            if (i < k) {
                cur += m.count(s[i]);  // Count the vowels in the first window of size k
            } else {
                cur += m.count(s[i]) - m.count(s[i - k]);  // Slide the window: add current char, remove char left outside
            }
            ans = max(ans, cur);  // Update the maximum count of vowels
        }
        
        return ans;  // Return the maximum count of vowels in any window of size k
    }
};
