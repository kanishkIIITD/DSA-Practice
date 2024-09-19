class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int m = s + (e-s)/2;
        while(s < e){
            if(m%2 == 1)
                m--;
            if(nums[m] == nums[m+1])
                s = m+2;
            else
                e = m;
            m = s + (e-s)/2;
        }
        return nums[m];
    }
};