class Solution {
public:
    int dx[4] = {1 , 0 , -1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    int minimumObstacles(vector<vector<int>> &a) {
        int n = a.size();
        int m = a[0].size();
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> q;
        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        dist[0][0] = 0;
        q.push({0 , {0 , 0}});
        while(!q.empty()) {
            pair<int , pair<int , int>> p = q.top();
            q.pop();
            int cost = p.first;
            int x = p.second.first , y = p.second.second;
            for(int i=0 ; i<4 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if(a[nx][ny] && dist[nx][ny] > cost + 1) {
                        dist[nx][ny] = cost + 1;
                        q.push({cost + 1 , {nx , ny}});
                    } else if(!a[nx][ny] && dist[nx][ny] > cost) {
                        dist[nx][ny] = cost;
                        q.push({cost , {nx , ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};