class Solution {
public:
    void getSubsets(vector<int>&nums, int i, vector<vector<int>>&ans, vector<int>&temp){
        // base
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        int current = INT_MIN;
        int idx = i;
        while(idx < nums.size()){
            if(current < nums[idx]){
                current = nums[idx];
                temp.push_back(current);
                getSubsets(nums, idx+1, ans, temp);
                temp.pop_back();
            }
            idx++;
        }
        ans.push_back(temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        getSubsets(nums, 0, ans, temp);
        return ans;
    }
};