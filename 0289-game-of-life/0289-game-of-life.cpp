class Solution {
public:
    // Function to check the validity of the neighbor's coordinates
    bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) { 
        // Vectors to check the 8 possible neighbors' coordinates
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1}; // Changes in x
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1}; // Changes in y
        
        // First pass: calculate the state of each cell
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                
                int count_live_neighbors = 0; // Count live neighbors
                
                // Check all 8 neighbors
                for (int i = 0; i < 8; i++) {
                    int curr_x = row + dx[i], curr_y = col + dy[i];
                    if (isValidNeighbor(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1)
                        count_live_neighbors++;
                }
                
                // Apply rules of the Game of Life
                if (board[row][col] == 1 && (count_live_neighbors < 2 || count_live_neighbors > 3))
                    board[row][col] = -1; // Mark as dead in the next state
                
                if (board[row][col] == 0 && count_live_neighbors == 3)
                    board[row][col] = 2; // Mark as live in the next state
            }
        }
        
        // Second pass: update the board to the next state
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] >= 1)
                    board[row][col] = 1; // Set to alive
                else
                    board[row][col] = 0; // Set to dead
            }
        }
    }
};
