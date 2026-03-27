class Solution {
public:
    void solve(vector<int>& candidates, int i, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(i >= candidates.size() || target < 0)
            return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates, i, target - candidates[i], ans, temp);
        temp.pop_back();
        solve(candidates, i+1, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, temp);
        return ans;
    }
};