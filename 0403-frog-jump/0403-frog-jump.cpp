class Solution {
public:
    bool solve(vector<int>& stones, int index, int k, vector<vector<int>>& dp){
        if(index == stones.size() - 1)
            return true;
        if(dp[index][k] != -1)
            return dp[index][k];
        for(int i = index+1; i < stones.size(); i++){
            int dist = stones[i] - stones[index];
            if(dist < k-1)
                continue;
            if(dist > k+1)
                break;
            if(solve(stones, i, dist, dp))
                return dp[index][k] = 1;
        }
        return dp[index][k] = 0;
    }
    bool canCross(vector<int>& stones) {
        if (stones.size() > 1 && stones[1] != 1) 
            return false;
        int k = 1;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(stones, 1, k, dp);
    }
};