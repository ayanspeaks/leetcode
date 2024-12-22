class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& qs) {
    vector<int> mono, idx, res(qs.size());
    for (int i = 0; i < qs.size(); ++i) {
        sort(begin(qs[i]), end(qs[i]));
        if (qs[i][0] == qs[i][1] || heights[qs[i][0]] < heights[qs[i][1]])
            res[i] = qs[i][1];
        else
            idx.push_back(i);
    }
    sort(begin(idx), end(idx), [&](int i, int j) { return qs[i][1] > qs[j][1]; });
    int j = heights.size() - 1;
    for (int i : idx) {
        int a = qs[i][0], b = qs[i][1];
        while (j > b) {
            while (!mono.empty() && heights[mono.back()] <= heights[j])
                mono.pop_back();
            mono.push_back(j--);
        }
        auto it = upper_bound(rbegin(mono), rend(mono), a, [&](int i, int j){
            return heights[i] < heights[j];
        });
        res[i] = it == rend(mono) ? -1 : *it;
    }
    return res;
}
};