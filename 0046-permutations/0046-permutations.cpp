class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<int>& hash, vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }
        for(int ind = 0; ind < nums.size(); ind++){
            if(hash[ind] == 0){
                temp.push_back(nums[ind]);
                hash[ind] = 1;
                solve(nums, ind+1, temp, hash, ans);
                temp.pop_back();
                hash[ind] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> hash(nums.size());
        solve(nums, 0, temp, hash, ans);
        return ans;
    }
};