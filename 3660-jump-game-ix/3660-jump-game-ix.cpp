class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preMax(n, nums[0]);
        for(int i = 1; i < n; i++)
            preMax[i] = max(preMax[i-1], nums[i]);
        int mini = 1e9;
        for(int i = n-1; i >= 0; i--){
            if(preMax[i] > mini)
                ans[i] = ans[i+1];
            else
                ans[i] = preMax[i];
            mini = min(mini, nums[i]);
        }
        return ans;
    }
};