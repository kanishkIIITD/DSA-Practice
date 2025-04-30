class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int start, ansS, ansE;
        for(int i = 0; i < nums.size(); i++){
            if(sum == 0)
                start = i;
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
                ansS = start;
                ansE = i;
            }
            if(sum < 0)
                sum = 0;
        }
        for(int i = ansS; i < ansE + 1; i++)
            cout << nums[i] << " ";
        return maxi;
    }
};