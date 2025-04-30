class Solution {
public: 
    int solve(int i, vector<int>&nums, vector<int>& dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        int opt1 = nums[i] + solve(i+2, nums, dp);
        int opt2 = solve(i+1, nums, dp);
        return dp[i] = max(opt1, opt2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, -1);
        return solve(0, nums, dp);
    }
};