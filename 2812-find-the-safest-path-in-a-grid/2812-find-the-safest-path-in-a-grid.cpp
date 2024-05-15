class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid[0][0] || grid[grid.size()-1][grid[0].size()-1])return 0;
        auto valid=[&](int i, int j)->bool{
            return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
        };
        vector<vector<int>>v(grid.size(), vector<int>(grid[0].size(), 1e9));
        queue<pair<int, int>>q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){q.push({i, j}); v[i][j]=0;}
            }
        }
        int r[4]={-1, 1, 0, 0}, c[4]={0, 0, -1, 1};
        while(!q.empty()){
            int x=q.front().first, y=q.front().second;
            q.pop();
            int val=v[x][y];
            for(int k=0; k<4; k++){
                int row=r[k]+x, col=c[k]+y;
                if(valid(row, col) && v[row][col]>1+val){
                    v[row][col]=1+val;
                    q.push({row, col});
                }
            }
        }
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        priority_queue<pair<int, pair<int, int>>>p;
        p.push({v[0][0], {0, 0}});
        v[0][0]=1;
        while(!p.empty()){
            int x=p.top().second.first, y=p.top().second.second, val=p.top().first;
            p.pop();
            if(x==grid.size()-1 && y==grid[0].size()-1)return val;
            for(int k=0; k<4; k++){
                int row=r[k]+x, col=y+c[k];
                if(valid(row, col) && !vis[row][col]){
                    vis[row][col]=1;
                    int mini=min(val, v[row][col]);
                    p.push({mini, {row, col}});
                }
            }
        }
        return -1;
    }
};