class Solution {
public:
    void updateVis(vector<vector<int>>& vis, int row, int col, int n, int val) {
        for(int i = 1; row + i < n; i++) {
            vis[row + i][col] += val;
            if(col - i >= 0) vis[row + i][col - i] += val;
            if(col + i < n)  vis[row + i][col + i] += val;
        }
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans, vector<vector<int>>& vis, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(vis[row][col] == 0){
                board[row][col] = 'Q';
                updateVis(vis, row, col, n, 1);
                solve(row+1, board, ans, vis, n);
                updateVis(vis, row, col, n, -1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, board, ans, vis, n);
        return ans;
    }
};