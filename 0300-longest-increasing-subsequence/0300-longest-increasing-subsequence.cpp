class Solution {
public:
    // int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
    //     if(i == nums.size())
    //         return 0;
    //     if(dp[i][prev] != -1)
    //         return dp[i][prev];
    //     int notpick = solve(i+1, prev, nums, dp);
    //     int pick = 0;
    //     if(prev == 0 || nums[i] > nums[prev-1])
    //         pick = 1 + solve(i+1, i+1, nums, dp);
    //     return dp[i][prev] = max(pick, notpick);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1));
        vector<int> dp(n+1);
        for(int i = n-1; i >= 0; i--){
            vector<int> temp(n+1);
            for(int prev = n-1; prev >= 0; prev--){
                int notpick = dp[prev];
                int pick = 0;
                if(prev == 0 || nums[i] > nums[prev-1])
                    pick = 1 + dp[i+1];
                temp[prev] = max(pick, notpick);
            }
            dp = temp;
        }
        return dp[0];
        // return solve(0, 0, nums, dp);
    }
};