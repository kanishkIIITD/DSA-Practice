class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = 0;
        int maxLen = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0 && k > 0){
                k--;
            }
            else if(nums[r] == 0 && k == 0){
                while(nums[s] == 1){
                    s++;
                }
                s++;
            }
            maxLen = max(maxLen, r-s+1);
        }
        return maxLen;
    }
};