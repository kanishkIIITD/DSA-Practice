class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[row][col] = 1;
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == '1' && !vis[nr][nc])
                dfs(nr, nc, grid, vis, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }
        return count;
    }
};