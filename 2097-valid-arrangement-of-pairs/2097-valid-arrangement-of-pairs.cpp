class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, vector<int>> m;
    unordered_map<int, int> cnt;
    for (auto &p : pairs) {
        m[p[0]].push_back(p[1]);
        ++cnt[p[0]];
        --cnt[p[1]];
    }
    auto head = find_if(begin(cnt), end(cnt), [&](const auto &p){ return p.second > 0; });
    vector<int> route, stack{head != end(cnt) ? head->first : pairs[0][0]};
    vector<vector<int>> res;
    while (!stack.empty()) {
        while (!m[stack.back()].empty()) {
            int i = stack.back();
            stack.push_back(m[i].back());
            m[i].pop_back();
        }
        route.push_back(stack.back());
        stack.pop_back();
    }
    for (int i = route.size() - 1; i > 0; --i)
        res.push_back({route[i], route[i - 1]});
    return res;
}
};