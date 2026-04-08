class Solution {
public:
    const long long MOD = 1000000000 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto  query: queries){
            // auto [l, r, k, v] = query;
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            if(l >= n)
                continue;
            int idx = l;
            while(idx <= r && idx < n){
                nums[idx] = (1LL *nums[idx] * v) % MOD;
                idx += k;
            }
        }
        int xorr = 0;
        for(auto it: nums)
            xorr ^= it;
        return xorr;
    }
};