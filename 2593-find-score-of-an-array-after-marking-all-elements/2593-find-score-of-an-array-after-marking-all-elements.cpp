class Solution {
public:
    long long findScore(vector<int>& x) {
         long long  n = x.size(), ans = 0;

         vector<bool>vis(n);
         vector<pair<int, int>>v;

         for(int i = 0; i < n ;i++) v.push_back({x[i], i});
         sort(v.begin(), v.end());

        for(auto [val, id] : v){
            if(vis[id])continue;
             
            ans += val;
            vis[id] = 1,
            vis[min((int)n + 1, id + 1)] = 1,
            vis[max(0, id - 1)] = 1;
        }

        return ans;
    }
};