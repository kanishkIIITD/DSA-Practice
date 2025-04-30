class Solution {
public:
    bool canRob(vector<int>& nums, int mid, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    bool canRob(int mid, int k, vector<int>&nums){
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        // int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
        // while (left <= right) {
        //     int mid = (left + right) / 2;
        //     if (canRob(nums, mid, k)) {
        //         ans = mid;
        //         right = mid - 1;
        //     } else {
        //         left = mid + 1;
        //     }
        // }
        // return ans;

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(canRob(mid, k, nums)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
