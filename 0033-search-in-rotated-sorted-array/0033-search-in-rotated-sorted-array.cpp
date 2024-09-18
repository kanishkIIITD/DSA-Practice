class Solution {
public:

    int pivot(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            int m = s + (e-s)/2;

            if(s == e)
                return s;
            if(m+1 <=e && nums[m] > nums[m+1])
                return m;
            if (m-1 >= s && nums[m-1] > nums[m])
                return m-1;

            if(nums[m] < nums[s])
                e = m-1;
            else 
                s = m+1;
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target){
        int s = start;
        int e = end;

        while(s <= e){
            int m = s + (e-s)/2;

            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                e = m-1;
            else 
                s = m+1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivotIndex = pivot(nums);
        
        int ans = -1;
        if(nums[0] <= target && target <= nums[pivotIndex])
            ans = binarySearch(nums, 0, pivotIndex, target);
        else
            ans = binarySearch(nums, pivotIndex+1, nums.size()-1, target);

        return ans;
    }
};