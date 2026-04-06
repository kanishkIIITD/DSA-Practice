class Solution {
public:
    // int solve(int i, int j, string& word1, string& word2, int m, int n, vector<vector<int>>& dp){
    //     if(i == m)
    //         return n - j;
    //     if(j == n)
    //         return m - i;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(word1[i] == word2[j])
    //         return dp[i][j] = solve(i+1, j+1, word1, word2, m, n, dp);
    //     else
    //         return dp[i][j] = 1 + min(solve(i, j+1, word1, word2, m, n, dp), solve(i+1, j, word1, word2, m, n, dp));
    // }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1));
        vector<int> dp(n+1);
        for(int j = 0; j < n; j++)
            dp[j] = n - j;
        for(int i = m-1; i >= 0; i--){
            vector<int> temp(n+1);
            temp[n] = m - i;
            for(int j = n-1; j >= 0; j--){
                if(word1[i] == word2[j])
                    temp[j] = dp[j+1];
                else
                    temp[j] = 1 + min(temp[j+1], dp[j]);
            }
            dp = temp;
        }
        return dp[0];
        // return solve(0, 0, word1, word2, m, n, dp);
    }
};