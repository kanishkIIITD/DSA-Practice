class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: If the array has only 1 element
        if (n == 1) return nums[0];
        
        // Edge case: If the single element is at the very beginning
        if (nums[0] != nums[1]) return nums[0];
        
        // Edge case: If the single element is at the very end
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 0, high = n-1;
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            else if(mid % 2 == 0){
                if(nums[mid-1] == nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(mid % 2 == 1){
                if(nums[mid-1] == nums[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};