class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                vis[0][i] = 1;
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
                vis[m-1][i] = 1;
            }
        }
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                vis[i][n-1] = 1;
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            board[row][col] = 'T';
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 'O' && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
                else if(board[i][j] = 'O')
                    board[i][j] = 'X';
            }
        }
    }
};