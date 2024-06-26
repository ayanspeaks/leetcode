class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        
        int n = matrix.size(), m = matrix[0].size();
        int up = 0, down = n-1, left = 0, right = m-1; 
        
        while(res.size() < n*m){
            for(int j=left; j<=right && res.size()<n*m; j++)
                res.push_back(matrix[up][j]);
            
            for(int i=up+1; i<=down-1 && res.size()<n*m; i++)
                res.push_back(matrix[i][right]);
            
            for(int j=right; j>=left && res.size()<n*m; j--)
                res.push_back(matrix[down][j]);
            
            for(int i=down-1; i>=up+1 && res.size()<n*m; i--)
                res.push_back(matrix[i][left]);
            
            left++; right--; up++; down--;
        }
        return res;
    }
};