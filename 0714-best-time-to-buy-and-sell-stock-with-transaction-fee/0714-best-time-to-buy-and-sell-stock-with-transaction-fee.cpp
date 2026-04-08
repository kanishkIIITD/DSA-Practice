class Solution {
public:
    int solve(int i, bool buy, int fee, vector<int>& prices, vector<vector<int>> &dp){
        if(i == prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(solve(i+1, buy, fee, prices, dp), -prices[i] + solve(i+1, !buy, fee, prices, dp));
        else
            return dp[i][buy] = max(solve(i+1, buy, fee, prices, dp), prices[i] - fee + solve(i+1, !buy, fee, prices, dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2));
        vector<int> dp(2);
        for(int i = n-1; i >= 0; i--){
            vector<int> temp(2);
            for(int buy = 0; buy < 2; buy++){
                if(buy)
                    temp[buy] = max(dp[buy], -prices[i] + dp[!buy]);
                else
                    temp[buy] = max(dp[buy], prices[i] - fee + dp[!buy]);
            }
            dp = temp;
        }
        return dp[1];
        // return solve(0, true, fee, prices, dp);
    }
};