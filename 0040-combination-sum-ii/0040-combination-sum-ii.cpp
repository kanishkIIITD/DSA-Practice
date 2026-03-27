class Solution {
public:
    void solve(vector<int>& candidates, int i, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i >= candidates.size() || target < 0)
            return;
        temp.push_back(candidates[i]);
        solve(candidates, i+1, target - candidates[i], ans, temp);
        temp.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        solve(candidates, i+1, target, ans, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, temp);
        return ans;
    }
};