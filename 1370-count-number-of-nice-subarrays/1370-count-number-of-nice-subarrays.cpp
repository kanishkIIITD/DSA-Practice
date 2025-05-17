class Solution {
public:
    int utility(vector<int>&nums, int k){
        int count = 0;
        int l = 0;
        int currOdd = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] % 2 == 1)
                currOdd++;
            while(currOdd > k){
                if(nums[l] % 2 == 1)
                    currOdd--;
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return utility(nums, k) - utility(nums, k-1);
    }
};