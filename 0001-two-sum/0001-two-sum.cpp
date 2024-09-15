class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int newTarget = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(newTarget == nums[j] && j != i && ans.empty()){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};