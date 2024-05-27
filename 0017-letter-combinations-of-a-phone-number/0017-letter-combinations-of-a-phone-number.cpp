class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    string digit, st;

    void solve(int id) {
        if(id == digit.size()) {
            ans.push_back(st);
            return;
        }

        for(auto c: mp[digit[id]]) {
            st.push_back(c);
            solve(id+1);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        digit = digits;
        solve(0);
        return ans;
    }
};