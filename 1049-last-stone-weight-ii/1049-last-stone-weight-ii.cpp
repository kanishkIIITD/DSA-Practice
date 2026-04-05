class Solution {
public:
    int solve(int i, int sum1, int sum2, vector<int>& stones, vector<vector<int>>& dp){
        if(i == stones.size())
            return abs(sum1 - sum2);
        if(dp[i][sum1] != -1)
            return dp[i][sum1];
        int pick = solve(i+1, sum1+stones[i], sum2-stones[i], stones, dp);
        int notpick = solve(i+1, sum1, sum2, stones, dp);
        return dp[i][sum1] = min(pick, notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for(auto stone: stones) total += stone;
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(total + 1, -1));
        return solve(0, 0, total, stones, dp);
    }
};