class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1)
            return grid[i][j];
        else if(i >= m || j >= n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i+1, j, m, n, grid, dp), solve(i, j+1, m, n, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // return solve(0, 0, m, n, grid, dp);
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = 0; i < m; i++)
            dp[i][n] = INT_MAX;
        for(int i = 0; i < n; i++)
            dp[m][i] = INT_MAX;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) {
                    continue;
                }
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};