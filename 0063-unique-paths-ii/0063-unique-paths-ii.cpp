class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0)
    //         return 1;
    //     if(i < 0 || j < 0)
    //         return 0;
    //     if(obstacleGrid[i][j] == 1)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int up = solve(i-1, j, obstacleGrid, m, n, dp);
    //     int left = solve(i, j-1, obstacleGrid, m, n, dp);
    //     return dp[i][j] = up + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, obstacleGrid, m, n, dp);

        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i == 0 && j == 0)
        //             continue;
        //         if(obstacleGrid[i][j] == 1){
        //             dp[i][j] = 0;
        //             continue;
        //         }
                
        //         int up = i-1 >= 0 ? dp[i-1][j] : 0;
        //         int left = j-1 >= 0 ? dp[i][j-1] : 0;
        //         dp[i][j] = up + left;
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                
                int up = i-1 >= 0 ? dp[j] : 0;
                int left = j-1 >= 0 ? curr[j-1] : 0;
                curr[j] = up + left;
            }
            dp = curr;
        }
        return dp[n-1];
    }
};