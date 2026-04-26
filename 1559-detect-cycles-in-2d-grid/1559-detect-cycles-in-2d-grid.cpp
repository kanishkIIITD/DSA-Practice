class Solution {
public:
    bool solve(int i, int j, int pi, int pj, char ch, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[i][j] = 1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == ch){
                if(nr == pi && nc == pj) continue;
                if(vis[nr][nc] == 1)
                    return true;
                else if(!vis[nr][nc]){
                    if(solve(nr, nc, i, j, ch, grid, vis, m, n))
                        return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j])
                    if(solve(i, j, -1, -1, grid[i][j], grid, vis, m, n))
                        return true;
            }
        }
        return false;
    }
};