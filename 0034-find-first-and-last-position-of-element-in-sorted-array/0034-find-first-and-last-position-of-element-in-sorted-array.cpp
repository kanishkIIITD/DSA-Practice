class Solution {
public:
    int firstPosition(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int mid, ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        } 
        return ans;
    }
    int lastPosition(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int mid, ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        } 
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int starting = firstPosition(nums, target);
        int ending = lastPosition(nums, target);
        return {starting, ending};
    }
};