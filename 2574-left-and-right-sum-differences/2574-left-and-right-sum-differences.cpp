class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums)
            sum += num;
        int n = nums.size();
        vector<int> ans(n);
        int lsum = 0;
        for(int i = 0; i < n; i++){
            int rsum = sum - lsum - nums[i];
            ans[i] = abs(lsum - rsum);
            lsum += nums[i];
        }
        return ans;
    }
};