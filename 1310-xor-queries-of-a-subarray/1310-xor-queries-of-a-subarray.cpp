class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> x(arr.size() + 1), res;
    for (auto i = 1; i <= arr.size(); ++i) 
        x[i] = x[i - 1] ^ arr[i - 1];
    for (auto &q : queries) 
        res.push_back(x[q[0]] ^ x[q[1] + 1]);
    return res;
}
};