class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<int> &dp){
        if(i == nums.size()-1)
            return 0;
        if(dp[i] != -2)
            return dp[i];
        int maxi = -1;
        for(int j = i+1; j < nums.size(); j++){
            int diff = nums[j] - nums[i];
            if(-1 * target <= diff && diff <= target){
                int jump = solve(j, nums, target, dp);
                if(jump != -1)
                    maxi = max(maxi, 1 + jump);
            }
        }
        return dp[i] = maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -2);
        return solve(0, nums, target, dp);
    }
};