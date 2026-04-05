class Solution {
public:
    int solve(int i, int current_sum, int target, vector<int>& nums, vector<vector<int>>& dp, int totalSum){
        // 1. Base Case: Reached the end of the array
        if(i == nums.size()) {
            if(current_sum == target)
                return 1;
            return 0;
        }
        
        // 2. Safe Memoization Check
        if(dp[i][current_sum + totalSum] != -1)
            return dp[i][current_sum + totalSum];
            
        // 3. Explore + and - paths by modifying the current_sum
        int add = solve(i+1, current_sum + nums[i], target, nums, dp, totalSum);
        int sub = solve(i+1, current_sum - nums[i], target, nums, dp, totalSum);
        
        // 4. Memoize and return
        return dp[i][current_sum + totalSum] = sub + add;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto num: nums) totalSum += num;
        
        if(abs(target) > totalSum)
            return 0;
            
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*totalSum + 1, -1));
        
        // Pass 0 as our starting current_sum
        return solve(0, 0, target, nums, dp, totalSum);
    }
};