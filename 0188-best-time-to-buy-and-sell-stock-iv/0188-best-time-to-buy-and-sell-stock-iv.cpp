class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1)));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap < k+1; cap++){
                    if(buy)
                        dp[i][buy][cap] = max(dp[i+1][buy][cap], -prices[i] + dp[i+1][!buy][cap]);
                    else
                        dp[i][buy][cap] = max(dp[i+1][buy][cap], prices[i] + dp[i+1][!buy][cap-1]);
                }
            }
        }
        return dp[0][1][k];
    }
};