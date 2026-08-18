class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int, int> mp;
        for(auto x: nums)
            mp[x]++;
        if(k == 1){
            int maxi = INT_MIN;
            for(auto [k, v]: mp){
                if(v == 1){
                    maxi = max(maxi, k);
                }
            }
            return maxi == INT_MIN ? -1 : maxi;
        }
        int start = nums[0];
        int startV = mp[start];
        int end = nums[n-1];
        int endV = mp[end];
        if(startV == 1 && endV == 1){
            return start < end ? end : start;
        }
        else if(startV == 1)
            return start;
        else if(endV == 1)
            return end;
        else
            return -1;
    }
};