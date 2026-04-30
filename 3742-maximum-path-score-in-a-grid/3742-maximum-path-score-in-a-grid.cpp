class Solution {
public:
    int solve(int r, int c, int k, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>> &dp){
        if(k < 0)
            return -1;
        if(r == m-1 && c == n-1){
            if(grid[r][c] == 1 || grid[r][c] == 2)
                k -= 1;
            if(k < 0)
                return -1;
            return grid[r][c];
        }
        if(dp[r][c][k] != -2)
            return dp[r][c][k];
        int dr[2] = {0, 1};
        int dc[2] = {1, 0};
        int maxi = -1;
        for(int i = 0; i < 2; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < m && 0 <= nc && nc < n){
                int cost = 0;
                if(grid[r][c] == 1 || grid[r][c] == 2)
                    cost = 1;
                int sol = solve(nr, nc, k - cost, grid, m, n, dp);
                if(sol != -1)
                    maxi = max(maxi, grid[r][c] + sol);
            }
        }
        return dp[r][c][k] = maxi;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -2)));
        return solve(0, 0, k, grid, m, n, dp);
    }
};