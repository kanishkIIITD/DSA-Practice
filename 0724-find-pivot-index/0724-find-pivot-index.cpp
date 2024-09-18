class Solution {
public:
    int vectorSum(vector<int>& nums, int s, int e){
        int sum = 0;
        for(int i = s; i <= e; i++){
            sum += nums[i];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int s = i-1;
            int e = i+1;
            int m = s + (e-s)/2;
            int leftSum = vectorSum(nums, 0, m-1);
            int rightSum = vectorSum(nums, m+1, nums.size()-1);
            if(leftSum == rightSum)
                return m;
            else if(leftSum < rightSum)
                s = m+1;
            else 
                e = m-1;
            m = s + (e-s)/2;
        }
        return -1;
    }
    
};