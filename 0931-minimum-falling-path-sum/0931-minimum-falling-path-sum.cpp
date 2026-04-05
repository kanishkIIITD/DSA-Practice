class Solution {
public:
    // int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(j < 0 || j >= n)
    //         return 1e9;
    //     if(i == n-1)
    //         return matrix[i][j];
    //     if(dp[i][j] != 1e9)
    //         return dp[i][j];
    //     int left = matrix[i][j] + solve(i+1, j-1, n, matrix, dp);
    //     int down = matrix[i][j] + solve(i+1, j, n, matrix, dp);
    //     int right = matrix[i][j] + solve(i+1, j+1, n, matrix, dp);
    //     return dp[i][j] = min({left, down, right});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));
        vector<int> dp(n+1, 1e9);
        for(int j = 0; j < n; j++){
            dp[j] = matrix[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            vector<int> temp(n+1, 1e9);
            for(int j = n-1; j >= 0; j--){
                int down = dp[j];
                int left = (j > 0) ? dp[j-1] : 1e9;
                int right = (j < n-1) ? dp[j+1] : 1e9;
                
                temp[j] = matrix[i][j] + min({left, down, right});
            }
            dp = temp;
        }
        for(int i = 0; i < n; i++)
            mini = min(mini, dp[i]);
        return mini;
    }
};