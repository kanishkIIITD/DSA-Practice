class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //     if(i >= triangle.size())
    //         return 0;
    //     if(dp[i][j] != 1e9)
    //         return dp[i][j];
    //     return dp[i][j] = triangle[i][j] + min(solve(i+1, j, triangle, dp), solve(i+1, j+1, triangle, dp));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int> dp(n+1);
        // return solve(0, 0, triangle, dp);
        for(int i = n-1; i >= 0; i--){
            vector<int> temp(n+1);
            for(int j = triangle[i].size()-1; j >= 0; j--){
                temp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
            dp = temp;
        }
        return dp[0];
    }
};