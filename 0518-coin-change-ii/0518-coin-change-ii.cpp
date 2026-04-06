class Solution {
public:
    // int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(i == coins.size()){
    //         if(amount == 0) 
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[i][amount] != -1)
    //         return dp[i][amount];
    //     int notpick = solve(i+1, amount, coins, dp);
    //     int pick = 0;
    //     if(amount >= coins[i])
    //         pick = solve(i, amount - coins[i], coins, dp);
    //     return dp[i][amount] = pick + notpick;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1));
        vector<unsigned long long> dp(amount+1);
        // return solve(0, amount, coins, dp);
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<unsigned long long> temp(amount+1);
            for(int j = 0; j <= amount; j++){
                unsigned long long notpick = dp[j];
                unsigned long long pick = 0;
                if(j >= coins[i])
                    pick = temp[j-coins[i]];
                temp[j] = pick + notpick;
            }
            dp = temp;
        }
        return dp[amount];
    }
};