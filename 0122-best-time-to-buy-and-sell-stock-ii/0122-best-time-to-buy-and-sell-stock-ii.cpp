class Solution {
public:
    // int solve(int index, int buy, vector<int>&prices, vector<vector<int>> &dp){
    //     if(index == prices.size())
    //         return 0;
    //     if(dp[index][buy] != -1)
    //         return dp[index][buy];
    //     if(buy){
    //         return dp[index][buy] = max((-prices[index] + solve(index+1, 0, prices, dp)), solve(index+1, 1, prices, dp));
    //     }
    //     else
    //         return dp[index][buy] = max((prices[index] + solve(index+1, 1, prices, dp)), solve(index+1, 0, prices, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> dp(2, 0);
        vector<int> next(2, 0);
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy < 2 ; buy++){
                if(buy){
                    dp[buy] = max((-prices[index] + next[0]), next[1]);
                }
                else
                    dp[buy] = max((prices[index] + next[1]), next[0]);
            }
            next = dp;
        }
        return next[1];
    }
};