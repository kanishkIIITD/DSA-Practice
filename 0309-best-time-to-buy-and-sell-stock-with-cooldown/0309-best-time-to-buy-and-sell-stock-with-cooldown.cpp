class Solution {
public:
    // int solve(int i, bool buy, bool cooldown, vector<int>& prices, vector<vector<vector<int>>> &dp){
    //     if(i == prices.size())
    //         return 0;
    //     if(dp[i][buy][cooldown] != -1)
    //         return dp[i][buy][cooldown];
    //     if(cooldown){
    //         return dp[i][buy][cooldown] = solve(i+1, buy, !cooldown, prices, dp);
    //     }
    //     else if(buy){
    //         return dp[i][buy][cooldown] = max(solve(i+1, buy, cooldown, prices, dp), -prices[i] + solve(i+1, !buy, cooldown, prices, dp));
    //     }
    //     else{
    //         return dp[i][buy][cooldown] = max(solve(i+1, buy, cooldown, prices, dp), prices[i] + solve(i+1, !buy, !cooldown, prices, dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2)));
        vector<vector<int>> dp(2, vector<int>(2));
        for(int i = n-1; i >= 0; i--){
            vector<vector<int>> temp(2, vector<int>(2));
            for(int buy = 0; buy < 2; buy++){
                for(int cooldown = 1; cooldown >= 0; cooldown--){
                    if(cooldown)
                        temp[buy][cooldown] = dp[buy][!cooldown];
                    else if(buy)
                        temp[buy][cooldown] = max(dp[buy][cooldown], -prices[i] + dp[!buy][cooldown]);
                    else
                        temp[buy][cooldown] = max(dp[buy][cooldown], prices[i] + dp[!buy][!cooldown]);
                }
            }
            dp = temp;
        }
        return dp[1][0];
        // return solve(0, true, false, prices, dp);
    }
};