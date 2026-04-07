class Solution {
public:
    // int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
    //     if(j == t.size())
    //         return 1;
    //     if(i == s.size())
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(s[i] == t[j])
    //         return dp[i][j] = solve(i+1, j+1, s, t, dp) + solve(i+1, j, s, t, dp);
    //     else 
    //         return dp[i][j] = solve(i+1, j, s, t, dp);
    // }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        // vector<vector<unsigned int>> dp(m+1, vector<unsigned int>(n+1));
        vector<unsigned int> dp(n+1);
        dp[n] = 1;
        for(int i = m-1; i >= 0; i--){
            vector<unsigned int> temp(n+1);
            temp[n] = 1;
            for(int j = n-1; j >= 0; j--){
                if(s[i] == t[j])
                    temp[j] = dp[j+1] + dp[j];
                else 
                    temp[j] = dp[j];
            }
            dp = temp;
        }
        return dp[0];
        // return solve(0, 0, s, t, dp);
    }
};