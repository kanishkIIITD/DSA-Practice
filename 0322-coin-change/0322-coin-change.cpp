class Solution {
public:
    // int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(i == coins.size()){
    //         if(amount == 0)
    //             return 0;
    //         return 1e9;
    //     }
    //     if(dp[i][amount] != -1)
    //         return dp[i][amount];
    //     int notpick = solve(i+1, amount, coins, dp);
    //     int pick = 1e9;
    //     if(amount >= coins[i])
    //         pick = 1 + solve(i, amount - coins[i], coins, dp);
    //     return dp[i][amount] = min(pick, notpick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));
        dp[n][0] = 0;
        // int sol = solve(0, amount, coins, dp);
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                int notpick = dp[i+1][j];
                int pick = 1e9;
                if(j >= coins[i])
                    pick = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(pick, notpick);
            }
        }
        return dp[0][amount] == 1e9 ? -1 : dp[0][amount];
    }
};