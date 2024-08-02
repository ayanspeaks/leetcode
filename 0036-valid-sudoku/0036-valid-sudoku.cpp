class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;  // Set to store unique row, column, and box identifiers
        
        // Iterate through each cell in the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {  // If the cell is not empty
                    // Create unique identifiers for row, column, and 3x3 sub-box
                    string row = "row" + to_string(i) + board[i][j];
                    string col = "col" + to_string(j) + board[i][j];
                    string box = "box" + to_string((i / 3) * 3 + (j / 3)) + board[i][j];
                    
                    // Check if the identifier already exists in the set
                    if (s.find(row) == s.end() && s.find(col) == s.end() && s.find(box) == s.end()) {
                        // If not found, insert them into the set
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    } else {
                        // If found, the board is not valid
                        return false;
                    }
                }
            }
        }
        // If no duplicates found, the board is valid
        return true;
    }
};
