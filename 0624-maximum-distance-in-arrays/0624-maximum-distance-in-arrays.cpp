class Solution {
public:
   int maxDistance(vector<vector<int>>& v) {
       int mx = v[0][v[0].size() - 1], mn = v[0][0];
       int n = v.size(), ans = 0;

       for (int i = 1; i < n; i++) {
           ans = max({ans, v[i][v[i].size() - 1] - mn, mx - v[i][0]});
           mn = min(mn, v[i][0]);
           mx = max(mx, v[i][v[i].size() - 1]);
       }

       mx = v[n-1][v[n-1].size() - 1];
       mn = v[n-1][0];

       for (int i = n - 2; i >= 0; i--) {
           ans = max({ans, v[i][v[i].size() - 1] - mn, mx - v[i][0]});
           mn = min(mn, v[i][0]);
           mx = max(mx, v[i][v[i].size() - 1]);
       }

       return ans;
   }
};