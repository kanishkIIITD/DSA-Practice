class Solution {
public:
    void getCombinations(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>& temp, int i){
        // base condidtion
        if(target < 0 || i > candidates.size())
            return;
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        int current = -1;
        int index = i;
        while(index < candidates.size()){
            if(current < candidates[index]){
                current = candidates[index];
                temp.push_back(current);
                getCombinations(candidates, target - current, ans, temp, index+1);
                temp.pop_back();
            }
            index++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        getCombinations(candidates, target, ans, temp, 0);
        return ans;
    }
};