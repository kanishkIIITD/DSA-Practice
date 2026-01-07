class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j = 0; 
       while(j < nums.size()){
        if(nums[j] == 0)
            break;
        j++;
       }
        int i = j+1;
        while(i < nums.size()){
            if(nums[i] != 0)
                break;
            i++;
        }
        while(i < nums.size()){
            if(nums[i] == 0)
                i++;
            else{
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
        }
    }
};