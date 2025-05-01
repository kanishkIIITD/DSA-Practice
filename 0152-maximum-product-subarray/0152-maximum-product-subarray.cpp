class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int current_max = nums[0];
        int current_min = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // Store current_max before updating it, since current_min will use the old value
            int temp_max = max({num, current_max * num, current_min * num});
            int temp_min = min({num, current_max * num, current_min * num});

            current_max = temp_max;
            current_min = temp_min;

            result = max(result, current_max);
        }
        return result;
    }
};