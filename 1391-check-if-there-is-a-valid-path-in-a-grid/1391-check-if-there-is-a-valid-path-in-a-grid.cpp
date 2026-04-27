class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n){
        if(i == m-1 && j == n-1)
            return true;
        vis[i][j] = 1;
        int mp[7][2][2] = {
            {},                 // Index 0: Zero-initialized
            {{0, -1}, {0, 1}},  // Index 1: Left, Right
            {{-1, 0}, {1, 0}},  // Index 2: Up, Down
            {{0, -1}, {1, 0}},  // Index 3: Left, Down
            {{0, 1}, {1, 0}},   // Index 4: Right, Down
            {{0, -1}, {-1, 0}}, // Index 5: Left, Up
            {{0, 1}, {-1, 0}}   // Index 6: Right, Up
        };
        for(int k = 0; k < 2; k++){
            int ni = i + mp[grid[i][j]][k][0];
            int nj = j + mp[grid[i][j]][k][1];
            if(0 <= ni && ni < m && 0 <= nj && nj < n && !vis[ni][nj]){
                for(int u = 0; u < 2; u++){
                    int xi = ni + mp[grid[ni][nj]][u][0];
                    int xj = nj + mp[grid[ni][nj]][u][1];
                    if(xi == i && xj == j){
                        if(dfs(ni, nj, grid, vis, m, n))
                            return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        return dfs(0, 0, grid, vis, m, n);
    }
};