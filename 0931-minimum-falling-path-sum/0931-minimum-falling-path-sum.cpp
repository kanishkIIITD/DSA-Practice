class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= n)
            return 1e9;
        if(i == n-1)
            return matrix[i][j];
        if(dp[i][j] != 1e9)
            return dp[i][j];
        int left = matrix[i][j] + solve(i+1, j-1, n, matrix, dp);
        int down = matrix[i][j] + solve(i+1, j, n, matrix, dp);
        int right = matrix[i][j] + solve(i+1, j+1, n, matrix, dp);
        return dp[i][j] = min({left, down, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));
        for(int i = 0; i < n; i++)
            mini = min(mini, solve(0, i, n, matrix, dp));
        return mini;
    }
};