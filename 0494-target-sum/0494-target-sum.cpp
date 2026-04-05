class Solution {
public:
    int solve(int i, int target, vector<int>& nums){
        if(i == nums.size() && target == 0)
            return 1;
        if(i >= nums.size())
            return 0;
        int sub = solve(i+1, target+nums[i], nums);
        int add = solve(i+1, target-nums[i], nums);
        return sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};