class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Solution 1
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[abs(nums[i])] < 0)
        //         return abs(nums[i]);
        //     nums[abs(nums[i])] *= -1;
        // }
        // return -1;

        // Solution 2
        while(nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};