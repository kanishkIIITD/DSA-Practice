class Solution {
public:
    bool canRob(int mid, int k, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = (nums[0] <= mid) ? 1 : 0;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = max(
                dp[i-1],  // Skip current house
                (nums[i-1] <= mid) ? dp[i-2] + 1 : 0  // Rob current house if valid
            );
        }
        return dp[n] >= k;
    }


    int minCapability(vector<int>& nums, int k) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(canRob(mid, k, nums)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
