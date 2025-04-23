class Solution {
public:
    int getMax(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
            maxi = max(maxi, nums[i]);
        return maxi;
    }
    int getSum(vector<int>&nums, int mid, int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = getMax(nums);
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = getSum(nums, mid, threshold);
            if(sum <= threshold)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};