class Solution {
public:
    bool binSearch(vector<vector<int>>& matrix, int l,int r,int n,int tar){
        if(l == r){
            int row = l/n;
            int col = l%n;
            if(matrix[row][col] == tar){
                return true;
            }
            return false;
        }
        int m = (l+r)/2;
        int row = m/n;
        int col = m%n;
        if(matrix[row][col] == tar){
                return true;
        }
        if(matrix[row][col] < tar){
            return binSearch(matrix,m+1,r,n,tar);
        }
        return binSearch(matrix,l,m,n,tar);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = rows*cols -1;
        return binSearch(matrix,0,r,cols,target);
    }
};