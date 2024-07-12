class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int l = 0, r = 0;
        unordered_map<char, int> chars;
        while(r < s.length()){
            auto it = chars.find(s[r]);
            if(it != chars.end() && it->second >= l){
                l = it->second+1;
            } else {
                result = max(result,r-l+1);
            }
            chars[s[r]] = r;
            r++;
        }
        return result;
    }
};