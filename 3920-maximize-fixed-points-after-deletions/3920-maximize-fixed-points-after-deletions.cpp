class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> valid_pairs;
        for(int i = 0; i < nums.size(); i++){
            if(i >= nums[i])
                valid_pairs.push_back({i - nums[i], nums[i]});
        }
        sort(valid_pairs.begin(), valid_pairs.end());
        vector<int> lis;
        for(const auto& p: valid_pairs){
            int val = p.second;
            auto it = lower_bound(lis.begin(), lis.end(), val);
            if(it == lis.end())
                lis.push_back(val);
            else
                *it = val;
        }
        return lis.size();
    }
};