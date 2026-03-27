class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& temp){
        // if(target == 0){
        //     ans.push_back(temp);
        //     return;
        // }
        // if(i >= candidates.size() || target < 0)
        //     return;
        // temp.push_back(candidates[i]);
        // solve(candidates, i+1, target - candidates[i], ans, temp);
        // temp.pop_back();
        // while(i + 1 < candidates.size() && candidates[i] == candidates[i+1]) {
        //     i++;
        // }
        // solve(candidates, i+1, target, ans, temp);

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solve(candidates, i+1, target-candidates[i], ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, temp);
        return ans;
    }
};