class Solution {
public:
    // int solve(int index, int buy, int cooldown, vector<int>&prices, vector<vector<vector<int>>> &dp){
    //     if(index == prices.size())
    //         return 0;
        
    //     if(dp[index][buy][cooldown] != -1)
    //         return dp[index][buy][cooldown];

    //     if(buy){
    //         if(cooldown){
    //             return dp[index][buy][cooldown] = solve(index+1, 1, 0, prices, dp);
    //         }
    //         else
    //             return dp[index][buy][cooldown] = max(-prices[index] + solve(index+1, 0, 0, prices, dp), solve(index+1, 1, 0, prices, dp));
    //     }
    //     else
    //         return dp[index][buy][cooldown] = max(prices[index] + solve(index+1, 1, 1, prices, dp), solve(index+1, 0, cooldown, prices, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        // return solve(0, 1, 0, prices, dp); //{index, buy, cooldown}

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, 0)));
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                for(int cooldown = 1; cooldown >= 0; cooldown--){
                    if(buy){
                        if(cooldown){
                            dp[index][buy][cooldown] = dp[index+1][1][0];
                        }
                        else
                            dp[index][buy][cooldown] = max(-prices[index] + dp[index+1][0][0], dp[index+1][1][0]);
                    }
                    else
                        dp[index][buy][cooldown] = max(prices[index] + dp[index+1][1][1], dp[index+1][0][cooldown]);
                }
            }
        }
        return dp[0][1][0];
    }
};