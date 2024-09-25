class Solution {
public:
    struct Trie {
    Trie* ch[26] = {};
    int cnt = 0;
    void insert(string &w, int i = 0) {
        auto n = this;
        for (auto c : w) {
            if (n->ch[c - 'a'] == nullptr)
                n->ch[c - 'a'] = new Trie();
            n = n->ch[c - 'a'];
            ++n->cnt;
        }
    }
    int count(string &w, int i = 0) {
        return cnt + (i == w.size() ? 0 : ch[w[i] - 'a']->count(w, i + 1));
    }
}; 
vector<int> sumPrefixScores(vector<string>& words) {
    Trie t;
    for (auto &w : words)
        t.insert(w);
    vector<int> res;
    for (auto &w : words)
        res.push_back(t.count(w));
    return res;
}
};