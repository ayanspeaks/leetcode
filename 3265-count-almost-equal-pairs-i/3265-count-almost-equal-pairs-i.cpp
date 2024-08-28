class Solution {
public:
    int countPairs(vector<int>& nums) {
    int ans = 0;
    map<int, int> freq;
    for(auto n: nums) { 
        freq[n]++; ans += freq[n] - 1; 
        string s = to_string(n);
        string t = "000000";
        s = t.substr(0, 7 - s.size()) + s;
        unordered_set<int> st;
        for(int i = 0; i < s.size(); ++i){
            for(int j = i+1; j < s.size(); ++j){
                swap(s[i], s[j]);
                int temp = stoi(s); 
                if(temp != n)  ans += freq[temp];
                swap(s[i], s[j]);
            }
        }
    }
    return ans;
}
};