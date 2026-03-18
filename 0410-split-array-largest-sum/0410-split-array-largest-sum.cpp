class Solution {
public:
    int isPossible(vector<int>& nums, int k, int targetSum){
        int count = 1, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > targetSum){
                count++;
                sum = nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isPossible(nums, k, mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};