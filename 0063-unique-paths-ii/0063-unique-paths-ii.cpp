class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        int a[r][c];
        bool flag = false;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1)
            return 0;
        for(int i = 0; i < c; i++){
            if(flag || obstacleGrid[0][i]){ //presence of obstacle in the cell or previous cells in the row
                a[0][i] = 0;
                flag = true;
            }
            else
                a[0][i] = 1;
        }

         flag = false;

        for(int j = 1; j < r; j++){
            if(flag || obstacleGrid[j][0]){//presence of obstacle in the cell or previous cells in the column
                a[j][0] = 0;
                flag = true;
            }
            else
                a[j][0] = 1;
        }
        for(int i = 1; i < r; i++)
            for(int j = 1; j < c; j++){
                if(obstacleGrid[i][j] == 1)//obstacle
                     a[i][j] = 0;
                else
                    a[i][j] = a[i][j-1] + a[i-1][j];//can reach (i, j) through (i, j-1) or (i-1, j)
            }
            return a[r-1][c-1];
    }
};