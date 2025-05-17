class Solution {
public:
    int utility(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int count = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return utility(nums, k) - utility(nums, k-1);
    }
};