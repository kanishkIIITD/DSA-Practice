class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // The min must be in the right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // The min must be in the left half, including mid
                right = mid;
            } else {
                // nums[mid] == nums[right]
                // We aren't sure which half, but we can safely discard nums[right]
                right--;
            }
        }
        
        // left and right converge to the minimum element
        return nums[left];
    }
};