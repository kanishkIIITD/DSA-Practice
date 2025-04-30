class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&dp){
        int m = vis.size();
        int n = vis[0].size();
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        vis[i][j] = 1;

        int paths = 0;

        vector<int> dx = {0, 1};
        vector<int> dy = {1, 0};
        for(int k = 0; k < 2; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(0 <= nr && nr < m && 0 <= nc && nc < n && !vis[nr][nc]){
                paths += solve(nr, nc, vis, dp);
            }
        }
        vis[i][j] = 0;
        return dp[i][j] = paths;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int count = 0;
        count = solve(0, 0, vis, dp);
        return count;
    }
};