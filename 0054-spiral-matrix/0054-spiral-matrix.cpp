class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;  // Result vector to store the elements in spiral order
        if (matrix.empty() || matrix[0].empty()) return res;  // Return empty vector if matrix is empty
        
        int n = matrix.size(), m = matrix[0].size();  // Get the dimensions of the matrix
        int up = 0, down = n - 1, left = 0, right = m - 1;  // Initialize boundary pointers
        
        // Loop until we've processed all elements
        while (res.size() < n * m) {
            // Traverse from left to right on the top row
            for (int j = left; j <= right && res.size() < n * m; j++)
                res.push_back(matrix[up][j]);
            
            // Traverse from top to bottom on the right column
            for (int i = up + 1; i <= down - 1 && res.size() < n * m; i++)
                res.push_back(matrix[i][right]);
            
            // Traverse from right to left on the bottom row
            for (int j = right; j >= left && res.size() < n * m; j--)
                res.push_back(matrix[down][j]);
            
            // Traverse from bottom to top on the left column
            for (int i = down - 1; i >= up + 1 && res.size() < n * m; i--)
                res.push_back(matrix[i][left]);
            
            // Move the boundaries inward
            left++;
            right--;
            up++;
            down--;
        }
        return res;  // Return the result vector
    }
};
