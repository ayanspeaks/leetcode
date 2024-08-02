class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();  // Get the size of the matrix (assuming it's n x n)
        
        // Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);  // Swap the elements at (i, j) and (j, i)
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());  // Reverse the elements in the row
        }
    }
};
