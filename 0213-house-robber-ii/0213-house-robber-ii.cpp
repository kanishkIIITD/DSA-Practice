class Solution {
public:
    // int solve(int start, int last, vector<int>&nums, vector<int>&dp){
    //     if(start > last)
    //         return 0;
    //     if(dp[start] != -1)
    //         return dp[start];
    //     int opt1 = solve(start+1, last, nums, dp);
    //     int opt2 = nums[start] + solve(start+2, last, nums, dp);
    //     return dp[start] = max(opt1, opt2);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        vector<int> dp1(n+2, 0);
        vector<int> dp2(n+2, 0);
        // return max(solve(0, n-2, nums, dp1), solve(1, n-1, nums, dp2));
        for(int i = n-2; i >= 0; i--){
            int opt1 = dp1[i+1];
            int opt2 = nums[i] + dp1[i+2];
            dp1[i] = max(opt1, opt2);
        }
        for(int i = n-1; i >= 1; i--){
            int opt1 = dp2[i+1];
            int opt2 = nums[i] + dp2[i+2];
            dp2[i] = max(opt1, opt2);
        }
        return max(dp1[0], dp2[1]);
    }
};