class Solution {
public:
    int solve(int i, bool buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap == 0 || i == prices.size())
            return 0;
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        if(buy)
            return dp[i][buy][cap] = max(solve(i+1, buy, cap, prices, dp), -prices[i] + solve(i+1, !buy, cap, prices, dp));
        else
            return dp[i][buy][cap] = max(solve(i+1, buy, cap, prices, dp), prices[i] + solve(i+1, !buy, cap-1, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3)));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap < 3; cap++){
                    if(buy)
                        dp[i][buy][cap] = max(dp[i+1][buy][cap], -prices[i] + dp[i+1][!buy][cap]);
                    else
                        dp[i][buy][cap] = max(dp[i+1][buy][cap], prices[i] + dp[i+1][!buy][cap-1]);
                }
            }
        }
        return dp[0][1][2];
        // return solve(0, true, 2, prices, dp);
    }
};