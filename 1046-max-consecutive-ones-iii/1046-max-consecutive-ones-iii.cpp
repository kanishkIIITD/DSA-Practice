class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = 0;
        int maxLen = 0;
        // vector<int> flip(nums.size(), 0);
        int numZeroes = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0 && k > 0){
                k--;
                // flip[r] = 1;
                numZeroes++;
            }
            else if(nums[r] == 0 && k == 0){
                // while(flip[s] == 0 && s < r)
                while(nums[s] == 1){
                    s++;
                }
                // flip[s] = 0;
                // flip[r] = 1;
                s++;
            }
            maxLen = max(maxLen, r-s+1);
        }
        return maxLen;
    }
};