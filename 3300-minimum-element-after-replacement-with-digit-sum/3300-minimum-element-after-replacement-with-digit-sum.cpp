class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = digitSum(nums[i]);
            mini = min(mini, nums[i]);
        }        
        return mini;
    }
};