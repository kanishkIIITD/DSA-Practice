class Solution {
public:
    // int pivot(vector<int>&nums){
    //     int s = 0;
    //     int e = nums.size()-1;
    //     while(s <= e){
    //         if(s == e)
    //             return s;
    //         int m = s + (e-s)/2;
    //         if(m+1 <= e && nums[m] > nums[m+1])
    //             return m;
    //         if(m-1 >= s &&nums[m-1] > nums[m])
    //             return m-1;
    //         if(nums[m] < nums[s])
    //             e = m-1;
    //         else 
    //             s = m+1;
    //     }
    //     return -1;
    // }

    // int binarySearch(vector<int>&nums, int start, int end, int target){
    //     int s = start;
    //     int e = end;
    //     while(s <= e){
    //         int m = s + (e-s)/2;
    //         if(nums[m] == target)
    //             return m;
    //         else if(nums[m] > target)
    //             e = m-1;
    //         else 
    //             s = m+1;
    //     }
    //     return -1;
    // }

    // int search(vector<int>& nums, int target) {
    //     int pivotIndex = pivot(nums); 
    //     if(nums[0] <= target && target <= nums[pivotIndex]){
    //         return binarySearch(nums, 0, pivotIndex, target);
    //     }
    //     else{
    //         return binarySearch(nums, pivotIndex+1, nums.size()-1, target);
    //     }
    // }

    int search(vector<int>&nums, int target){
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            int m = (s+e)/2;
            if(nums[m] == target)
                return m;
            // left sorted
            if(nums[s] <= nums[m]){
                if(nums[s] <= target && target <= nums[m]){
                    e = m-1;
                }
                else
                    s = m+1;
            }
            // right sorted
            else{
                if(nums[m] <= target && target <= nums[e]){
                    s = m+1;
                }
                else
                    e = m-1;
            }
        }
        return -1;
    }
};