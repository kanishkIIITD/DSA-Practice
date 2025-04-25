class Solution {
public:
    void getPermutations(vector<int>& nums, int i, vector<int>& temp, vector<int>& vis, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int idx = 0; idx < nums.size(); idx++){
            if(vis[idx] != 1){
                temp.push_back(nums[idx]);
                vis[idx] = 1;
                getPermutations(nums, i+1, temp, vis, ans);
                vis[idx] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(), 0); //0 - visited, 1 - not visited
        getPermutations(nums, 0, temp, vis, ans);
        return ans;
    }
};