class Solution {
    public:
        const long mod = 1e9 + 7;
        long dominoes(int i, int n, bool possible, vector<vector<int>>& dp) {
            if (i == n) return !possible;
            if (i > n) return 0;
            if(dp[i][possible] != -1)
                return dp[i][possible];
            if (possible)
                return dp[i][possible] = (dominoes(i + 1, n, false, dp) + 
                        dominoes(i + 1, n, true, dp)) % mod;
            return dp[i][possible] = (dominoes(i + 1, n, false, dp) + 
                    dominoes(i + 2, n, false, dp) + 
                    2L * dominoes(i + 2, n, true, dp)) % mod;
            }

        int numTilings(int n) {
            vector<vector<int>> dp(n+1, vector<int>(2, -1));
            return dominoes(0, n, false, dp);
        }
    };