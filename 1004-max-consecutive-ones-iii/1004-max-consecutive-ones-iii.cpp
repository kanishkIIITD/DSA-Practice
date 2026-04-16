class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0, maxi = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == 1){
                len++;
            }
            else if(nums[j] == 0 && k > 0){
                len++;
                k--;
            }
            else{
                while(k < 1){
                    if(nums[i] == 1){
                        i++;
                        len--;
                    }
                    else{
                        i++;
                        k++;
                        len--;
                    }
                }
                len++;
                k--;
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};