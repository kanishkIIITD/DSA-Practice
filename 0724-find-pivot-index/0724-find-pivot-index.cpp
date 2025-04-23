class Solution {
public:
    int getSum(vector<int>&nums, int start, int end){
        int sum = 0;
        for(int i = start; i <= end; i++)
            sum += nums[i];
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int s = i-1;
            int e = i+1;
            int m = s + (e-s)/2;
            int leftSum = getSum(nums, 0, m-1);
            int rightSum = getSum(nums, m+1, n-1);
            if(leftSum == rightSum)
                return m;
            else if(leftSum > rightSum)
                e = m-1;
            else 
                s = m+1;
        }
        return -1;
    }
};