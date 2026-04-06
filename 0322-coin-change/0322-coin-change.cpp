class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i == coins.size()){
            if(amount == 0)
                return 0;
            return 1e9;
        }
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int notpick = solve(i+1, amount, coins, dp);
        int pick = 1e9;
        if(amount >= coins[i])
            pick = 1 + solve(i, amount - coins[i], coins, dp);
        return dp[i][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int sol = solve(0, amount, coins, dp);
        return sol == 1e9 ? -1 : sol;
    }
};