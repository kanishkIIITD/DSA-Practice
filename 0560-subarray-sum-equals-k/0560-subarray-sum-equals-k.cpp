class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp; // <prefixSum, count>
        mp[0] = 1;
        int prefix = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            count += mp[prefix - k];
            mp[prefix] += 1;
        }
        return count;
    }
};