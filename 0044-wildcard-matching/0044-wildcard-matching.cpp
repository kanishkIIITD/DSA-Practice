class Solution {
public:
    // bool solve(int i, int j, string&s, string&p, vector<vector<int>>& dp){
    //     if(i == s.size() && j == p.size())
    //         return true;
    //     if(i == s.size()){
    //         for(int k = j; k < p.size(); k++){
    //             if(p[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if(j == p.size())
    //         return false;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(s[i] == p[j] || p[j] == '?')
    //         return dp[i][j] = solve(i+1, j+1, s, p, dp);
    //     if(p[j] == '*')
    //         return dp[i][j] = solve(i, j+1, s, p, dp) || solve(i+1, j, s, p, dp);
    //     return false;
    // }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[m][n] = 1;
        for(int j = 0; j < n; j++){
            bool flag = true;;
            for(int k = j; k < p.size(); k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                dp[m][j] = 1;
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == p[j] || p[j] == '?')
                    dp[i][j] = dp[i+1][j+1];
                else if(p[j] == '*')
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
            }
        }
        return dp[0][0];
        // return solve(0, 0, s, p, dp);
    }
};