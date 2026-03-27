class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int ind = i; ind < nums.size(); ind++){
            if(ind > i && nums[ind] == nums[ind-1])
                continue;
            temp.push_back(nums[ind]);
            solve(nums, ind+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, 0, temp, ans);
        return ans;
    }
};