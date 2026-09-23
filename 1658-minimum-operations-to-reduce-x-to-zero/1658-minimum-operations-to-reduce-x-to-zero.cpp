class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum - x;
        
        // If the target is exactly 0, we need to remove all elements
        if (target == 0) return nums.size();
        // If target is negative, it's impossible to sum exactly to x
        if (target < 0) return -1;
        
        int maxLen = -1;
        int currentSum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray summing to 'target'
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            
            // Shrink the window from the left if the sum exceeds our target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            // If we found a valid subarray, update the maximum length
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        // If maxLen is still -1, no valid subarray was found
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};