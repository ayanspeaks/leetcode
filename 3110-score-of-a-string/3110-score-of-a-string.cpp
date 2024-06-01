class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < s.length(); ++i) {
            int ascii1 = s[i - 1];
            int ascii2 = s[i];
            score += abs(ascii1 - ascii2);
        }
        return score;
    }
};