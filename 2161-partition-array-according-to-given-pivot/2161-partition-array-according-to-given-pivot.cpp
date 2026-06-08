class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), l = 0, r = n-1;
        int i = 0, j = n-1;
        vector<int> ans(n);
        while(i < n){
            if(nums[i] < pivot){
                ans[l] = nums[i];
                l++;
            }
            if(nums[j] > pivot){
                ans[r] = nums[j];
                r--;
            }
            i++;
            j--;
        }
        while(l <= r){
            ans[l] = pivot;
            l++;
        }
        return ans;
    }
};