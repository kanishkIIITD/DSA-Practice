class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector<vector<int>> &dp){
        if(i > j)
            return -1;
        if(dp[i][j] != -2)
            return dp[i][j];
        int both = solve(i+1, j-1, piles, dp);
        int first = piles[i] + max(both, solve(i+2, j, piles, dp));
        int last = piles[j] + max(both, solve(i, j-2, piles, dp));
        return dp[i][j] = max(first, last);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -2));
        int opt = solve(0, n-1, piles, dp);
        int total = 0;
        for(auto p: piles)
            total += p;
        return opt > (total - opt);
    }
};