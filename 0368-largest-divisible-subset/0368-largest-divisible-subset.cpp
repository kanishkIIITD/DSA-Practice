class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0){
                    if(1 + dp[prev] > dp[i]){
                        dp[i] = 1 + dp[prev];
                        parent[i] = prev;
                    }
                }
            }
        }
        int lastIndex = -1;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(dp[i] > maxi){
                lastIndex = i;
                maxi = dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(lastIndex != parent[lastIndex]){
            lastIndex = parent[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};