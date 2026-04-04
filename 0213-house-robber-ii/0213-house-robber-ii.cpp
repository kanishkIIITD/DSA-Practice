class Solution {
public:
    int solve(int start, int end, vector<int>& nums, vector<int>& dp){
        if(start > end)
            return 0;
        if(dp[start] != -1)
            return dp[start];
        int pick = nums[start] + solve(start+2, end, nums, dp);
        int notpick = solve(start+1, end, nums, dp);
        return dp[start] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[n-1];
        vector<int> dp1(n+2, -1);
        vector<int> dp2(n+2, -1);
        return max(solve(0, n-2, nums, dp1), solve(1, n-1, nums, dp2));
    }
};