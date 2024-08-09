class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
       int ans=0;
       int n=grid.size();
       int m=grid[0].size();

       for(int row=0;row<n-2;row++){
        for(int col=0;col<m-2;col++){
             unordered_set<int>mp;
            int rowtop=grid[row][col]+grid[row][col+1]+grid[row][col+2];
            mp.insert(grid[row][col]);
            mp.insert(grid[row][col+1]);
            mp.insert(grid[row][col+2]);
            int rowbottom=grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2];
            mp.insert(grid[row+2][col]);
            mp.insert(grid[row+2][col+1]);
            mp.insert(grid[row+2][col+2]);
           
            int colleft=grid[row][col]+grid[row+1][col]+grid[row+2][col];
            mp.insert(grid[row+1][col]);
            
            int colright=grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2];
            mp.insert(grid[row+1][col+2]);
           
            int diag1=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
            mp.insert(grid[row+1][col+1]);
            int diag2=grid[row+2][col]+grid[row+1][col+1]+grid[row][col+2];
           
           bool istrue=true;
            for(int i=1;i<=9;i++){
                if(mp.find(i)==mp.end())
                istrue=false;
                
            }
           
            if(istrue && rowtop==rowbottom && rowbottom==colleft && colleft==colright && colright==diag1 && diag1==diag2)
            ans++;
            
        }
       }

     return ans;
    }
};