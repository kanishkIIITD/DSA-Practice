class Solution {
public:
    int solve(int i, bool buy, bool cooldown, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(i == prices.size())
            return 0;
        if(dp[i][buy][cooldown] != -1)
            return dp[i][buy][cooldown];
        if(cooldown){
            return dp[i][buy][cooldown] = solve(i+1, buy, !cooldown, prices, dp);
        }
        else if(buy){
            return dp[i][buy][cooldown] = max(solve(i+1, buy, cooldown, prices, dp), -prices[i] + solve(i+1, !buy, cooldown, prices, dp));
        }
        else{
            return dp[i][buy][cooldown] = max(solve(i+1, buy, cooldown, prices, dp), prices[i] + solve(i+1, !buy, !cooldown, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, true, false, prices, dp);
    }
};