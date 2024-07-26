class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, 1e6));
        for(auto& a: edges)
            dist[a[0]][a[1]] = dist[a[1]][a[0]] = a[2];
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
        int minC = 1e9, result = -1;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                count += dist[i][j] <= dt;
            }
            if(count <= minC)
                result = i, minC = count;
        }
        return result;
    }
};