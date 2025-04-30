class Solution {
public:
    // int solve(int index, int buy, int k, vector<int>&prices, vector<vector<vector<int>>> &dp){
    //     if(k >= 2)
    //         return 0;
    //     if(index == prices.size())
    //         return 0;
    //     if(dp[index][buy][k] != -1)
    //         return dp[index][buy][k] ;
    //     if(buy){
    //         return dp[index][buy][k] = max(-prices[index] + solve(index+1, 0, k, prices, dp), solve(index+1, 1, k, prices, dp));
    //     }   
    //     else{
    //         return dp[index][buy][k] = max(prices[index] + solve(index+1, 1, k+1, prices, dp), solve(index+1, 0, k, prices, dp));
    //     } 
    
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        // return solve(0, 1, 0, prices, dp);

        int k_max = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k_max + 1, 0)));
        for (int index = n-1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int k = k_max; k >= 0; k--) {
                    if (buy) {
                        // Buy option: subtract price, move to "sell" state
                        int take = (k >= 0) ? (-prices[index] + dp[index+1][0][k]) : INT_MIN;
                        int notTake = dp[index+1][1][k];
                        dp[index][buy][k] = max(take, notTake);
                    } else {
                        // Sell option: add price, decrement transactions
                        int take = (k > 0) ? (prices[index] + dp[index+1][1][k-1]) : INT_MIN;
                        int notTake = dp[index+1][0][k];
                        dp[index][buy][k] = max(take, notTake);
                    }
                }
            }
        }
        return dp[0][1][k_max]; // Start with "buy" state and k_max transactions
    }
};