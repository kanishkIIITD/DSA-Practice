class Solution {
public:
    void getPermutations(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int idx = i; idx < nums.size(); idx++){
            swap(nums[i], nums[idx]);
            temp.push_back(nums[i]);
            getPermutations(nums, i+1, temp, ans);
            swap(nums[i], nums[idx]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        // vector<int> vis(nums.size(), 0); //0 - visited, 1 - not visited
        // getPermutations(nums, 0, temp, vis, ans);
        getPermutations(nums, 0, temp, ans);
        return ans;
    }
};