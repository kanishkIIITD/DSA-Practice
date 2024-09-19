class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int s = 0;
        // int e = nums.size()-1;
        // int m = s + (e-s)/2;
        // while(s < e){
        //     if(m%2 == 1)
        //         m--;
        //     if(nums[m] == nums[m+1])
        //         s = m+2;
        //     else
        //         e = m;
        //     m = s + (e-s)/2;
        // }
        // return nums[m];

        // Solution 2:
        int s = 0; 
        int e = nums.size()-1;
        while(s <= e){
            if(s == e)
                return nums[s];
            int m = s + (e-s)/2;
            if(m%2 == 0){
                if(nums[m] == nums[m+1])
                    s = m+2;
                else
                    e = m;
            }
            else{
                if(nums[m] == nums[m-1])
                    s = m+1;
                else
                    e = m-1;
            }
        }
        return -1;
    }
};