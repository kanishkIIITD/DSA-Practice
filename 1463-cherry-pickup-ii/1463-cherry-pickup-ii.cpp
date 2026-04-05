class Solution {
public:
    int solve(int row, int col1, int col2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return -1e8;
        if(row == m-1){
            if(col1 == col2)
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
        // return solve(0, 0, n-1, m, n, grid, dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    dp[m-1][i][j] = grid[m-1][i];
                else
                    dp[m-1][i][j] = grid[m-1][i] + grid[m-1][j];
            }
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                for(int k = 0; k < n; k++){
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value = 0;
                            if(j == k)
                                value = grid[i][j];
                            else
                                value = grid[i][j] + grid[i][k];
                            int next_j = j + dj1;
                            int next_k = k + dj2;
                            
                            if(next_j >= 0 && next_j < n && next_k >= 0 && next_k < n) {
                                value += dp[i+1][next_j][next_k];
                            } else {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j][k] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};