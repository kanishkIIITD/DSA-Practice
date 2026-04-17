class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, maxi = 0, zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                zero++;
            if(zero > k){
                if(nums[j] == 0)
                    zero--;
                j++;
            }
            if(zero <= k)
                maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};