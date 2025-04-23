class Solution {
public:
    int getMin(vector<int>&nums, int s, int e){
        int mini = INT_MAX;
        for(int i = s; i <= e; i++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[s] <= nums[m]){
                ans = min(ans, getMin(nums, s, m));
                s = m+1;
            }
            else{
                ans = min(ans, getMin(nums, m, e));
                e = m-1;
            }
        }
        return ans;
    }
};