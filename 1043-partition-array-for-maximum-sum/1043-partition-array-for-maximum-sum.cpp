class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>& dp){
        if(i == arr.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int maxi = INT_MIN;
        int len = 0;
        int ans = INT_MIN;
        int size = min((int)arr.size(), i+k);
        for(int j = i; j < size; j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + solve(j+1, k, arr, dp);
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(0, k, arr, dp);
    }
};