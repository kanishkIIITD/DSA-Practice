class Solution {
public:
    // int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
    //     if(i == m-1 && j == n-1)
    //         return 1;
    //     else if(i >= m || j >= n)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1));
        vector<int> dp(n+1);
        // return solve(0, 0, m, n, dp);
        dp[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            vector<int> temp(n+1);
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) {
                    temp[j] = 1;
                    continue;
                }
                temp[j] = dp[j] + temp[j+1];
            }
            dp = temp;
        }
        return dp[0];
    }
};