class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string t;
        for(int i = 0;i < s.size();i++) {
            t += to_string((int)(s[i]-96));
        }
        while(k--) {
            ans = 0;
            for(int i = 0;i < t.size();i++) {
                ans += (t[i]-'0');
            }
            t = to_string(ans);
        }
        return ans;
    }
};