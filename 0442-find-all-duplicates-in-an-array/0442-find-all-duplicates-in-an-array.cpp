class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0;
        while(i < n-1){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
                i+=2;
            }
            else
                i++;
        }
        return ans;
    }
};