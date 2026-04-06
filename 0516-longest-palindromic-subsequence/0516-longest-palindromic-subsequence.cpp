class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp){
        if(i > j)
            return 0;
        if(i == j && s[i] == s[j])
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = 2 + solve(i+1, j-1, s, dp);
        else
            return dp[i][j] = max(solve(i, j-1, s, dp), solve(i+1, j, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, dp);
    }
};