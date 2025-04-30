class Solution {
public:
    int solve(int index, int buy, int fee, vector<int>&prices, vector<vector<int>> &dp){
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        if(buy){
            return dp[index][buy] = max(-prices[index] + solve(index+1, 0, fee, prices, dp), solve(index+1, 1, fee, prices, dp));
        }
        else{
            return dp[index][buy] = max(prices[index] - fee + solve(index+1, 1, fee, prices, dp), solve(index+1, 0, fee, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};