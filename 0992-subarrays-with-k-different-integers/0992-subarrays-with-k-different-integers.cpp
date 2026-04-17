class Solution {
public:
    int helper(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int count = 0, j = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            while(mp.size() > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            count += (i - j + 1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};