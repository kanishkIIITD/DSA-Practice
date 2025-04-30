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
        // vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        // return solve(n-1, sum/2, nums, dp);

        vector<vector<int>> dp(n, vector<int>(sum/2+1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= sum/2)
            dp[0][nums[0]] = true;
        for(int index = 1; index < n; index++){
            for(int target = 1; target < sum/2+1; target++){
                bool notTake = dp[index-1][target];
                bool take = target >= nums[index] ? dp[index-1][target - nums[index]] : false;
                dp[index][target] = take || notTake;
            }
        }
        return dp[n-1][sum/2];
    }
};