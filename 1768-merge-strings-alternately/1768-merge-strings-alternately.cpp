class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         int n = word1.size();
        int m = word2.size();
        string ans = "";

        for (int i = 0; i < n && i < m; ++i) {
            ans += word1[i];
            ans += word2[i];
        }

        if (n > m) {
            ans += word1.substr(m);
        } else if (n < m) {
            ans += word2.substr(n);
        }

        return ans;
    }
};