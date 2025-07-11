class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&dp){
    //     int m = vis.size();
    //     int n = vis[0].size();
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
        
    //     vis[i][j] = 1;

    //     int paths = 0;

    //     vector<int> dx = {0, 1};
    //     vector<int> dy = {1, 0};
    //     for(int k = 0; k < 2; k++){
    //         int nr = i + dx[k];
    //         int nc = j + dy[k];
    //         if(0 <= nr && nr < m && 0 <= nc && nc < n && !vis[nr][nc]){
    //             paths += solve(nr, nc, vis, dp);
    //         }
    //     }
    //     vis[i][j] = 0;
    //     return dp[i][j] = paths;
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // // int count = 0;
        // // count = solve(0, 0, vis, dp);
        // // return count;

        // // dp[m-1][n-1] = 1;
        // // vis[m-1][n-1] = 1;
        // for(int i = m-1; i >= 0; i--){
        //     for(int j = n-1; j >= 0; j--){
        //         if(i == m-1 && j == n-1)
        //             continue;
        //         // vis[i][j] = 1;

        //         int paths = 0;

        //         vector<int> dx = {0, 1};
        //         vector<int> dy = {1, 0};
        //         for(int k = 0; k < 2; k++){
        //             int nr = i + dx[k];
        //             int nc = j + dy[k];
        //             if(0 <= nr && nr < m && 0 <= nc && nc < n){
        //                 paths += dp[nr][nc];
        //             }
        //         }
        //         // vis[i][j] = 0;
        //         dp[i][j] = paths;
        //     }
        // }
        // return dp[0][0];

        vector<int> dp(n, 1); // Initialize with 1's for first row
    
        for(int i = 1; i < m; i++) {       // Start from second row
            for(int j = 1; j < n; j++) {   // Start from second column
                dp[j] += dp[j-1]; // dp[j] = top (old dp[j]) + left (dp[j-1])
            }
        }
        
        return dp[n-1];
    }
};