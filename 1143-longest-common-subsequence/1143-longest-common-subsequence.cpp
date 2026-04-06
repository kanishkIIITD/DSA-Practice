class Solution {
public:
    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        if(i >= text1.size() || j >= text2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2, dp);
        else 
            return dp[i][j] = max(solve(i, j+1, text1, text2, dp), solve(i+1, j, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1));
        vector<int> dp(n+1);
        for(int i = m-1; i >= 0; i--){
            vector<int> temp(n+1);
            for(int j = n-1; j >= 0; j--){
                if(text1[i] == text2[j])
                    temp[j] = 1 + dp[j+1];
                else 
                    temp[j] = max(temp[j+1], dp[j]);
            }
            dp = temp;
        }
        return dp[0];
        // return solve(0, 0, text1, text2, dp);
    }
};