class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> ans(n);
        function<void(int, int)> dfs = [&](int node, int parent) -> void {
            for(auto it : adj[node]){
                if(ans[it].empty() || ans[it].back() != parent){
                    ans[it].push_back(parent);
                    dfs(it, parent);
                }
            }
        };
        for(int i = 0; i < n; i++){
            dfs(i, i);
        }
        return ans;
    }
};