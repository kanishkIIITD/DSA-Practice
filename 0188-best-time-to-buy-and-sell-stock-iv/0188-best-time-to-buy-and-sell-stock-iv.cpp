class Solution {
public:
    // int solve(int index, int buy, int k, vector<int>&prices, vector<vector<vector<int>>> &dp){
    //         if(k == 0)
    //             return 0;
    //         if(index == prices.size())
    //             return 0;
    //         if(dp[index][buy][k] != -1)
    //             return dp[index][buy][k] ;
    //         if(buy){
    //             return dp[index][buy][k] = max(-prices[index] + solve(index+1, 0, k, prices, dp), solve(index+1, 1, k, prices, dp));
    //         }   
    //         else{
    //             return dp[index][buy][k] = max(prices[index] + solve(index+1, 1, k-1, prices, dp), solve(index+1, 0, k, prices, dp));
    //         }      
    //     }
    int maxProfit(int kmax, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solve(0, 1, k, prices, dp);

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(kmax+1, 0)));
        vector<vector<int>> dp(2, vector<int>(kmax+1, 0));
        vector<vector<int>> next(2, vector<int>(kmax+1, 0));
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                for(int k = 1; k < kmax+1; k++){
                    if(buy){
                        dp[buy][k] = max(-prices[index] + next[0][k], next[1][k]);
                    }   
                    else{
                        dp[buy][k] = max(prices[index] + next[1][k-1], next[0][k]);
                    }
                }
            }
            next = dp;
        }
        return next[1][kmax];
    }
};