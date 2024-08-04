class Solution {
    // Starting index of the encoded string
    int start = 0;

    // Recursive function to decode the string
    string Solve(string &s) {
        // Variable to store our answer
        string ans = "";

        // Traverse forward till we don't get a numeric character
        // or closing bracket or we reach the end
        while (start < s.length() && s[start] >= 'a' && s[start] <= 'z' && s[start] != ']') {
            ans.push_back(s[start++]);
        }

        // If we reach the end or we are at a closing bracket, we return the ans as it is
        if (start >= s.length() || s[start] == ']') {
            return ans;
        }

        // We have reached a numeric character
        string num = "";

        // Store the number to be repeated
        while (s[start] != '[') {
            num.push_back(s[start++]);
        }
        int n = stoi(num);

        // Jump one index from '[' and get the repeating substring
        start++;

        string repeat = Solve(s);

        // Attach the repeating substring to our ans
        for (int k = 0; k < n; k++) {
            ans += repeat;
        }

        // Jump one index from ']' and get the substring ahead of
        // the repeating substring if any
        start++;

        // Return ans
        return ans + Solve(s);
    }

public:
    string decodeString(string s) {
        return Solve(s);
    }
};
