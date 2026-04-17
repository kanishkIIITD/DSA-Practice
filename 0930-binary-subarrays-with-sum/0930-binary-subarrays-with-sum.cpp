class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int sum = 0, j = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum > goal){
                sum -= nums[j];
                j++;
            }
            count += (i - j + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s1 = helper(nums, goal);
        int s2 = helper(nums, goal-1);
        return s1 - s2;
    }
};