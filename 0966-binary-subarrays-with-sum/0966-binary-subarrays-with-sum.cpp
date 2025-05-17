class Solution
{
    public:
       	// utility function to calculate the no. of subarrays with sum less than equal to goal
        int utility(vector<int> &nums, int goal)
        {
            int count = 0;
            int l = 0;
            int sum = 0;
            for (int r = 0; r < nums.size(); r++)
            {
                sum += nums[r];
                while (sum > goal)
                {
                    sum -= nums[l];
                    l++;
                }
                count += r - l + 1;
            }
            return count;
        }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        if(goal == 0)
            return utility(nums, goal);
        return utility(nums, goal) - utility(nums, goal - 1);
    }
};