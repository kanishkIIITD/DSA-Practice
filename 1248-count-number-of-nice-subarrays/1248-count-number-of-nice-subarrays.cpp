class Solution {
public:
    int helper(vector<int>& nums, int k){
        int odd = 0, count = 0, j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1)
                odd++;
            while(odd > k){
                if(nums[j] % 2 == 1)
                    odd--;
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};