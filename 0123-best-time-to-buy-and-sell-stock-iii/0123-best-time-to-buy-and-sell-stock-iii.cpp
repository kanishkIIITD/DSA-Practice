class Solution {
public:
    int solve(int index, int buy, int k, vector<int>&prices, vector<vector<vector<int>>> &dp){
        if(k >= 2)
            return 0;
        if(index == prices.size())
            return 0;
        if(dp[index][buy][k] != -1)
            return dp[index][buy][k] ;
        if(buy){
            return dp[index][buy][k] = max(-prices[index] + solve(index+1, 0, k, prices, dp), solve(index+1, 1, k, prices, dp));
        }   
        else{
            return dp[index][buy][k] = max(prices[index] + solve(index+1, 1, k+1, prices, dp), solve(index+1, 0, k, prices, dp));
        } 
    
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 0, prices, dp);
    }
};