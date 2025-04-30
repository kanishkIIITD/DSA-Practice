class Solution {
public:
    bool solve(int index, int target, vector<int>&nums, vector<vector<int>> &dp){
        if(target == 0)
            return true;
        if(index == 0)
            return nums[0] == target;
        
        if(dp[index][target] != -1)
            return dp[index][target];

        bool notTake = solve(index-1, target, nums, dp);
        bool take = target >= nums[index] ? solve(index-1, target - nums[index], nums, dp) : false;
        return dp[index][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return solve(n-1, sum/2, nums, dp);

    }
};