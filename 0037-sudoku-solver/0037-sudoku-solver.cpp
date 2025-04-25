class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false; // Check column
            if (board[row][i] == c) return false; // Check row
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false; // Check sub-box
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // \U0001f6a8 Fixed: = instead of ==
                            if (solve(board)) return true;
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // All cells filled
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
