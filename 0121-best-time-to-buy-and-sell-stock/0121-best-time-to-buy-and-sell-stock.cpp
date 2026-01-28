class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - mini;
            ans = max(ans, profit);
            mini = min(mini, prices[i]);
        }
        return ans < 0 ? 0 : ans;
    }
};