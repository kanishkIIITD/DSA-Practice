class Solution {
public:
    int solve(int row, int col1, int col2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return -1e8;
        if(row == m-1){
            if( col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1e8)
            return dp[row][col1][col2];
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(col1 == col2)
                    value = grid[row][col1];
                else
                    value = grid[row][col1] + grid[row][col2];
                value += solve(row+1, col1 + dj1, col2 + dj2, m, n, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(n+1, -1e8)));
        return solve(0, 0, n-1, m, n, grid, dp);
    }
};