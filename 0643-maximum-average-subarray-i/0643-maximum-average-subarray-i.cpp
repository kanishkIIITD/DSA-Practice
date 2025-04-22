class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Brute Force
        // double ans = double(INT_MIN);
        // int n = nums.size();
        // for(int i = 0; i+k-1 < n; i++){
        //     double sum = 0;
        //     for(int j = i; j < i+k; j++)
        //         sum += (double)nums[j];
        //     if(sum/k > ans)
        //         ans = sum/k;
        // }
        // return ans;

        // Optimized
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, maxSum = INT_MIN;
        while(i < n){
            if(i-j < k){
                sum += nums[i];
                i++;
            }
            else{
                maxSum = max(maxSum, sum);
                sum -= nums[j];
                j++;
            }
        }
        maxSum = max(maxSum, sum);
        return (double)maxSum/k;
    }
};