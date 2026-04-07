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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, true, 2, prices, dp);
    }
};