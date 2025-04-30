class Solution {
public: 
    // int solve(int i, vector<int>&nums, vector<int>& dp){
    //     if(i >= nums.size())
    //         return 0;
        
    //     if(dp[i] != -1)
    //         return dp[i];

    //     int opt1 = nums[i] + solve(i+2, nums, dp);
    //     int opt2 = solve(i+1, nums, dp);
    //     return dp[i] = max(opt1, opt2);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n + 2, -1);
        // return solve(0, nums, dp);

        // dp[n] = 0;
        // dp[n+1] = 0;
        // for(int i = n-1; i >= 0; i--){
        //     int opt1 = nums[i] + dp[i+2];
        //     int opt2 = dp[i+1];
        //     dp[i] = max(opt1, opt2);
        // }
        // return dp[0];

        int next = 0;
        int next1 = 0;
        for(int i = n-1; i >= 0; i--){
            int opt1 = nums[i] + next1;
            int opt2 = next;
            int curr = max(opt1, opt2);
            next1 = next;
            next = curr;
        }
        return next;
    }
};