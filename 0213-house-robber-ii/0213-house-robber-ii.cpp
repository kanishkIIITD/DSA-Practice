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
        // vector<int> dp1(n+2, 0);
        // vector<int> dp2(n+2, 0);
        // return max(solve(0, n-2, nums, dp1), solve(1, n-1, nums, dp2));
        int a = 0;
        int b = 0;
        for(int i = n-2; i >= 0; i--){
            int opt1 = b;
            int opt2 = nums[i] + a;
            int c = max(opt1, opt2);
            a = b;
            b = c;
        }
        int x = 0;
        int y = 0;
        for(int i = n-1; i >= 1; i--){
            int opt1 = y;
            int opt2 = nums[i] + x;
            int z = max(opt1, opt2);
            x = y;
            y = z;
        }
        return max(b, y);
    }
};