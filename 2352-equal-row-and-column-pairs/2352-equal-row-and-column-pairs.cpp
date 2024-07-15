class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>,int > m ; 
        int res = 0 ; 
        for(int i = 0; i<grid.size();i++)
        {
            vector<int> curr ; 
            for(int j = 0; j<grid.size();j++){
            curr.push_back(grid[i][j]);
            }
           m[curr]++;
        }
        cout<<endl;
        for(int j = 0 ; j<grid.size();j++)
        {
            vector<int> temp; 
            for(int i = 0 ; i< grid.size();i++)
            temp.push_back(grid[i][j]);
            
            if(m.find(temp)!=m.end())
            res += m[temp];
        }
        return res; 
    }
};