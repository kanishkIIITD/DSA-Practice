class Solution {
public:
    int solve(int i, bool canBuy, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size())
            return 0;
        if(dp[i][canBuy] != -1)
            return dp[i][canBuy];
        int profit = 0;
        if(canBuy){
            int buy = -prices[i] + solve(i+1, !canBuy, prices, dp);
            int nothing = solve(i+1, canBuy, prices, dp);
            profit = max(buy, nothing);
        }
        else{
            int sell = prices[i] + solve(i+1, !canBuy, prices, dp);
            int nothing = solve(i+1, canBuy, prices, dp);
            profit = max(sell, nothing);
        }
        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(0, true, prices, dp);
    }
};