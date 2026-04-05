class Solution {
public:
    // int solve(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
    //     if(i == m-1 && j == n-1 && obstacleGrid[i][j] == 0)
    //         return 1;
    //     if(i >= m || j >= n || obstacleGrid[i][j] == 1)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] = solve(i+1, j, m, n, obstacleGrid, dp) + solve(i, j+1, m, n, obstacleGrid, dp);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<long long>> dp(m+1, vector<long long>(n+1));
        vector<long long> dp(n+1);
        // return solve(0, 0, m, n, obstacleGrid, dp);
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        dp[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            vector<long long> temp(n+1);
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    temp[j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1)
                    temp[j] = 0;
                else
                    temp[j] = dp[j] + temp[j+1];
            }
            dp = temp;
        }
        return dp[0];
    }
};