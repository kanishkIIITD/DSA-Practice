class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<int> dp(sum+1);
        dp[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<int> temp(sum+1);
            temp[0] = 1;
            for(int j = 1; j <= sum; j++){
                bool pick = false;
                if(j-arr[i] >= 0)
                    pick = dp[j-arr[i]];
                bool notpick = dp[j];
                temp[j] = pick || notpick;
            }
            dp = temp;
        }
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto num: nums) totalSum += num;
        if(totalSum % 2 == 1) return false;
        int target = totalSum / 2;
        return isSubsetSum(nums, target);
    }
};