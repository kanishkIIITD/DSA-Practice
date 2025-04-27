class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int i = 0;
        while(i+2 < nums.size()){
            if(nums[i+1] == 2 * (nums[i] + nums[i+2]))
                count++;
            i++;
        }
        return count;
    }
};