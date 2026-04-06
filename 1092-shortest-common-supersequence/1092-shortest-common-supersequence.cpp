class Solution {
public:
    void LCS(int n, int m, string& s1, string& s2, vector<vector<int>>& dp){
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else 
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        LCS(n, m, s1, s2, dp);
        string ans = "";
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                ans += s1[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] > dp[i][j + 1]) {
                ans += s1[i]; 
                i++;
            } else {
                ans += s2[j]; 
                j++;
            }
        }
        while(i < n){
            ans += s1[i];
            i++;
        }
        while(j < m){
            ans += s2[j];
            j++;
        }
        return ans;
    }
};